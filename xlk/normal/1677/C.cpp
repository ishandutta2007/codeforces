#include <bits/stdc++.h>
using namespace std;
int t, n;
int f[100020];
int a[100020];
int b[100020];
int c[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		f[x] = y;
		c[y] += c[x];
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			f[i] = i;
			c[i] = 1;
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			U(a[i], b[i]);
		}
		long long z = 0, m = n - 1;
		for (int i = 1; i <= n; i++)
		{
			if (F(i) == i && c[i] >= 2)
			{
				int u = c[i] - c[i] % 2;
				while (u > 0)
				{
					z += m * 2;
					m -= 2;
					u -= 2;
				}
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}