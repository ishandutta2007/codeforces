#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> dat[10005];
int n, w, v, u;
double target;

bool check(double t)
{
	for (int i = 0; i < n; i++)
	{
		double x1 = dat[i].first, y1 = dat[i].second,
			x2 = dat[i + 1].first, y2 = dat[i + 1].second;
		x1 -= t * v;
		x2 -= t * v;

		double angle1 = atan2(y1, x1);
		double angle2 = atan2(y2, x2);

		if (target > min(angle1, angle2) && target < max(angle1, angle2)) return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d%d", &n, &w, &v, &u);
	target = atan2(u, v);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
	}
	dat[n] = dat[0];

	if (check(0)) printf("%.9f", (double)w/u);
	else
	{
		double lo = 0, hi = 1e9;
		for (int i = 0; i < 200; i++)
		{
			double mid = (lo + hi) / 2;
			if (check(mid))
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}

		printf("%.9f", (lo+hi)/2+(double)w/u);
	}
}