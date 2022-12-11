#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
	int x,y;
} dat[100005];
constexpr double eps = 1e-9;
constexpr double PI = 3.14159265358979323846;

double ternary(int sx,int sy,int ex,int ey,int x,int y)
{
	double lo=0, hi=1;
	for (int i = 0; i < 60; i++)
	{
		double mid1 = lo + (hi - lo) / 3;
		double mid2 = lo + (hi - lo) * 2 / 3;

		double d1 = hypot(sx + (ex - sx) * mid1 - x, sy + (ey - sy) * mid1 - y);
		double d2 = hypot(sx + (ex - sx) * mid2 - x, sy + (ey - sy) * mid2 - y);
		if (d1<d2)
		{
			hi = mid2;
		}
		else lo = mid1;
	}
	return hypot(sx+(ex-sx)*lo-x, sy+(ey-sy)*lo-y);
}

int main()
{
	int n, x, y;
	scanf("%d%d%d",&n,&x,&y);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d",&dat[i].x,&dat[i].y);
	}

	dat[n] = dat[0];

	bool left = false, right = false;
	for (int i = 0; i < n; i++)
	{
		int sx = dat[0].x, sy = dat[0].y;
		int ex = dat[1].x, ey = dat[1].y;

		if (sy == ey)
		{
			if (sy != y) continue;
			if (min(sx,ex) <= x) left = true;
			if (max(sx,ex) >= x) right = true;
			continue;
		}

		if (min(sy,ey) > y) continue;
		if (max(sy,ey) < y) continue;

		double xx = sx + (double)(ex - sx) * (y - sy) / (ey - sy);
		if (xx <= x + eps) left = true;
		if (xx + eps >= x) right = true;
	}

	double dist = 0;
	for (int i = 0; i < n; i++)
		dist = max(dist, hypot(dat[i].x-x,dat[i].y-y));
	double sht = 1e100;

	if (!left || !right)
	{
		for (int i = 0; i < n; i++)
			sht = min(sht, ternary(dat[i].x,dat[i].y,dat[i+1].x,dat[i+1].y,x,y));
	}

	printf("%.9f\n", dist*dist*PI-sht*sht*PI);
}