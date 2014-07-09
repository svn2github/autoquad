/*
    This file is part of AutoQuad.

    AutoQuad is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AutoQuad is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with AutoQuad.  If not, see <http://www.gnu.org/licenses/>.

    Copyright � 2011-2014  Bill Nesbitt
*/

// NOTE: These parameters must be passed to GCC:
//
//  -fsingle-precision-constant
//

#ifndef _aq_h
#define _aq_h

#define USE_MAVLINK
#define USE_PRES_ALT		 	// uncomment to use pressure altitude instead of GPS
#define USE_SIGNALING                   // uncomment to use external signaling events and ports
//#define USE_QUATOS

#ifndef BOARD_VERSION
    #define BOARD_VERSION	6
#endif
#ifndef BOARD_REVISION
    #define BOARD_REVISION	0
#endif

#include "stm32f4xx.h"

#if BOARD_VERSION == 6
    #if BOARD_REVISION == 0
        #include "board_6_1.h"
    #elif BOARD_REVISION == 1
        #include "board_6_1a.h"
    #endif
#endif
#if BOARD_VERSION == 7
    #if BOARD_REVISION == 0
        #include "board_7_0.h"
    #endif
#endif
#if BOARD_VERSION == 8
    #if BOARD_REVISION == 1 || BOARD_REVISION == 2
        #include "board_m4.h"
    #endif
    #if BOARD_REVISION == 3
        #include "board_m4_r3.h"
    #endif
    #if BOARD_REVISION == 4
        #include "board_m4_r4.h"
    #endif
    #if BOARD_REVISION == 5
        #include "board_m4_r5.h"
    #endif
#endif

#ifndef M_PI
#define M_PI			3.14159265f
#define M_PI_2			(M_PI / 2.0f)
#endif

#define RAD_TO_DEG		(180.0f / M_PI)
#define DEG_TO_RAD		(M_PI / 180.0f)

#define GRAVITY			9.80665f	// m/s^2

#define AQ_US_PER_SEC		1000000

#ifndef NAN
#define NAN	__float32_nan
#endif

//#define CAN_CALIB	// transmit IMU data over CAN

extern volatile unsigned long counter;
extern volatile unsigned long minCycles;

#endif
