#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

#define INF 1000000100

int kx = 0, ky = 0, x[5][5], y[5][5], rx = INF, ry = rx, ex = -rx, ey = -ry;

bool ok(int x1, int y1, int x2, int y2)
{
	for (int i = 0; i < 4; i++)
		if (x1 == x[i][0] && y1 == y[i][0] && x2 == x[i][1] && y2 == y[i][1])
			return true;
	return false;
}

int main()
{
	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
				scanf("%d%d", &x[i][j], &y[i][j]);
			if (x[i][0] > x[i][1] || (x[i][0] == x[i][1] && y[i][0] > y[i][1]))
				{
					std::swap(x[i][0], x[i][1]);
					std::swap(y[i][0], y[i][1]);
				}
			if (x[i][0] < rx || (x[i][0] == rx && y[i][0] < ry))
				{
					rx = x[i][0];
 					ry = y[i][0];
				}
			if (x[i][1] > ex || (x[i][1] == ex && y[i][1] > ey))
				{
					ex = x[i][1];
 					ey = y[i][1];
				}
			if (x[i][0] == x[i][1])		
				kx++;	
			if (y[i][0] == y[i][1]) 
				ky++;	
		}
	if (kx != 2 || ky != 2)
		{
			puts("NO");
			return 0;
		}
	if (ok(rx, ry, rx, ey) && 
            ok(rx, ry, ex, ry) &&
            ok(rx, ey, ex, ey) &&
            ok(ex, ry, ex, ey))
		puts("YES");
	else puts("NO");
	return 0;
}