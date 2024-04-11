#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, p[Maxn];
double a[Maxn], sum[Maxn];
double get_val(int x, int y)
{
	return (sum[y] - sum[x - 1]) / (double) (y - x + 1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &a[i]), sum[i] = sum[i - 1] + a[i];
	n++;
	a[n] = 1e9;
	sum[n] = sum[n - 1] + a[n];
	p[n] = n;
	for (int i = n - 1; i >= 1; i--)
	{
		int now = i;
		while (true)
		{
			if (get_val(i, now) <= get_val(i, p[now + 1]))
			{
				p[i] = now;
				break;
			}
			now = p[now + 1];
		}
	}
	for (int now = 1; now != n; now = p[now] + 1)
		for (int i = now; i <= p[now]; i++)
			a[i] = (sum[p[now]] - sum[now - 1]) / (double) (p[now] - now + 1);
	for (int i = 1; i < n; i++)
		printf("%.10lf\n", a[i]);
	return 0;
}