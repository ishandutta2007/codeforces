#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 5010
#define inf 2147483647

int n, x[N], y[N], z[N];

inline double dist(int i, int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	double ans = inf;
	for (int i = 1; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			double d1 = dist(i, 0), d2 = dist(j, 0), d3 = dist(i, j);
			if (d1 > d2)
				std::swap(d1, d2);
			d3 -= d2 - d1;
			if (d3 >= 0)
				ans = std::min(ans, d2 + d3 / 2);
		}
	printf("%.7lf", ans);
}