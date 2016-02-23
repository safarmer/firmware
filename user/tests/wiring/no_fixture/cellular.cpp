/**
 ******************************************************************************
  Copyright (c) 2015 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#include "application.h"
#include "unit-test/unit-test.h"

#if Wiring_Cellular == 1

void checkIPAddress(const char* name, const IPAddress& address)
{
	if (address.version()==0 || address[0]==0)
	{
		Serial.print("address failed:");
		Serial.println(name);
		assertNotEqual(address.version(), 0);
		assertNotEqual(address[0], 0);
	}
}

test(cellular_config)
{
	checkIPAddress("local", Cellular.localIP());
}

#endif
