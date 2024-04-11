#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int f[200020];
int c[200020];
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
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			U(i, x);
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", c[F(i)], i < n ? ' ' : '\n');
		}
	}
	return 0;
}