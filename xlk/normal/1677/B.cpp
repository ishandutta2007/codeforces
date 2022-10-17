#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[1000020];
int p[1000020];
int r[1000020];
int c[1000020];
int z[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%s", &n, &m, s);
		for (int i = 0; i <= n; i++)
		{
			r[i] = 0;
		}
		for (int i = 0; i <= m; i++)
		{
			c[i] = 0;
		}
		for (int i = 0; i < n * m; i++)
		{
			p[i + 1] = p[i] + (s[i] == '1');
			z[i] = 0;
		}
		int u = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (c[i % m] == 0 && s[i] == '1')
			{
				c[i % m] = 1;
				u++;
			}
			z[i] = u;
		}
		for (int i = 0; i < m; i++)
		{
			u = 0;
			for (int j = i; j < n * m; j += m)
			{
				if (p[min(j + 1, n * m)] - p[max(j - m + 1, 0)] > 0)
				{
					u++;
				}
				z[j] += u;
			}
		}
		for (int i = 0; i < n * m; i++)
		{
			printf("%d%c", z[i], i == n * m - 1 ? '\n' : ' ');
		}
	}
	return 0;
}