#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const double eps = 1e-7;
int n, a, b, cnt1[Maxn], cnt2[Maxn];
double f[Maxn], p[Maxn], v[Maxn];
void work(double x, double y)
{
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1], cnt1[i] = cnt1[i - 1], cnt2[i] = cnt2[i - 1];
		if (f[i - 1] + p[i] - x > f[i]) f[i] = f[i - 1] + p[i] - x, cnt1[i] = cnt1[i - 1] + 1, cnt2[i] = cnt2[i - 1];
		if (f[i - 1] + v[i] - y > f[i]) f[i] = f[i - 1] + v[i] - y, cnt1[i] = cnt1[i - 1], cnt2[i] = cnt2[i - 1] + 1;
		if (f[i - 1] + p[i] + v[i] - p[i] * v[i] - x - y > f[i]) f[i] = f[i - 1] + p[i] + v[i] - p[i] * v[i] - x - y, cnt1[i] = cnt1[i - 1] + 1, cnt2[i] = cnt2[i - 1] + 1;
	}
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &v[i]);
	double l1 = 0, r1 = 1, l2, r2;
	while (r1 - l1 >= eps)
	{
		double mid1 = (l1 + r1) / 2;
		l2 = 0, r2 = 1;
		while (r2 - l2 >= eps)
		{
			double mid2 = (l2 + r2) / 2;
			work(mid1, mid2);
			if (cnt2[n] >= b) l2 = mid2;
			else r2 = mid2;
		}
		work(mid1, l2);
		if (cnt1[n] >= a) l1 = mid1;
		else r1 = mid1;
	}
	work(l1, l2);
	printf("%.10lf", f[n] + l1 * a + l2 * b);
	return 0;
}