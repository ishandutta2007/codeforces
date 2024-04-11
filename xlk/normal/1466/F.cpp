#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int f[500020];
int v[500020];
int n, m;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return 0;
	}
	int re = 1;
	if (v[x] && v[y])
	{
		re = 0;
	}
	else
	{
		v[y] |= v[x];
	}
	f[x] = y;
	return re;
}
int z[500020], zc;
int s = 1;
void zuo(int x)
{
	z[zc++] = x;
	s = s * 2 % mod;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int o, x, y;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d", &x);
			x = F(x);
			if (!v[x])
			{
				zuo(i);
				v[x] = 1;
			}
		}
		else
		{
			scanf("%d%d", &x, &y);
			if (U(x, y))
			{
				zuo(i);
			}
		}
	}
	printf("%d %d\n", s, zc);
	for (int i = 0; i < zc; i++)
	{
		printf("%d%c", z[i], i == zc - 1 ? '\n' : ' ');
	}
	return 0;
}