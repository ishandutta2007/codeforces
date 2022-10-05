#include <bits/stdc++.h>
#define y1 yy1
using namespace std;

const int Maxn = 1005;
int n, m, Px, Py, Qx, Qy, x1[Maxn], y1[Maxn], x2[Maxn], y2[Maxn];
struct cir
{
	int x, y;
	double r;
};
double dis(pair <int, int> x, pair <int, int> y)
{
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
int in(cir x, pair <int, int> y)
{
	if (abs(dis(make_pair(x.x, x.y), y) - x.r) <= 1e-7) return -1;
	return dis(make_pair(x.x, x.y), y) <= x.r;
}
double S(pair <int, int> x, pair <int, int> y, pair <int, int> z)
{
	double d1 = dis(x, y), d2 = dis(x, z), d3 = dis(y, z), d = (d1 + d2 + d3) / 2;
	if (d1 * d1 + d3 * d3 < d2 * d2 || d2 * d2 + d3 * d3 < d1 * d1) return 1e18;
	return sqrt(d * (d - d1) * (d - d2) * (d - d3));
}
bool check(cir x, pair <pair <int, int>, pair <int, int> > y)
{
	int res1 = in(x, y.first), res2 = in(x, y.second);
	if (res1 == -1 || res2 == -1 || res1 ^ res2) return true;
	if (!in(x, y.first) && 2 * S(make_pair(x.x, x.y), y.first, y.second) / dis(y.first, y.second) <= x.r) return true;
	return false;
}
int main()
{
	scanf("%d%d%d", &Px, &Py, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x1[i], &y1[i]);
	scanf("%d%d%d", &Qx, &Qy, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &x2[i], &y2[i]);
	for (int i = 1; i <= n; i++)
	{
		cir now = (cir){Qx - Px + x1[i], Qy - Py + y1[i], dis(make_pair(Px, Py), make_pair(Qx, Qy))};
		for (int j = 1; j <= m; j++)
		{
			if (check(now, make_pair(make_pair(x2[j], y2[j]), make_pair(x2[j % m + 1], y2[j % m + 1]))))
			{
				puts("YES");
				return 0;
			}
		}
	}
	swap(x1, x2), swap(y1, y2), swap(n, m), swap(Px, Qx), swap(Py, Qy);
	for (int i = 1; i <= n; i++)
	{
		cir now = (cir){Qx - Px + x1[i], Qy - Py + y1[i], dis(make_pair(Px, Py), make_pair(Qx, Qy))};
		for (int j = 1; j <= m; j++)
		{
			if (check(now, make_pair(make_pair(x2[j], y2[j]), make_pair(x2[j % m + 1], y2[j % m + 1]))))
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}