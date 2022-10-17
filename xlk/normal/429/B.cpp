#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1020][1020];
int e[1020][1020];
int f[1020][1020];
int g[1020][1020];
int h[1020][1020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			e[i][j] = max(e[i][j - 1], e[i - 1][j]) + a[i][j];
		}
		for (int j = m; j > 0; j--)
		{
			f[i][j] = max(f[i][j + 1], f[i - 1][j]) + a[i][j];
		}
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			g[i][j] = max(g[i][j - 1], g[i + 1][j]) + a[i][j];
		}
		for (int j = m; j > 0; j--)
		{
			h[i][j] = max(h[i][j + 1], h[i + 1][j]) + a[i][j];
		}
	}
	int z = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			z = max(z, e[i][j - 1] + f[i - 1][j] + g[i + 1][j] + h[i][j + 1]);
			z = max(z, g[i][j - 1] + e[i - 1][j] + h[i + 1][j] + f[i][j + 1]);
		}
	}
	printf("%d\n", z);
	return 0;
}