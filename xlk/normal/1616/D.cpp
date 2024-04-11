#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int a[50020];
int f[50020]; // no a[i]
int g[50020]; // no a[i-1], must a[i]
int h[50020]; // must a[i-1] a[i]
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(h, 0, sizeof h);
		f[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%d", &x);
		for (int i = 1; i <= n; i++)
		{
			f[i] = max(g[i-1], h[i-1]);
			g[i] = f[i-1] + 1;
			if ((i < 2 || a[i-1] + a[i] >= 2 * x))
			{
				h[i] = max(h[i], g[i-1] + 1);
				if ((i < 3 || a[i-2] + a[i-1] + a[i] >= 3 * x))
				{
					h[i] = max(h[i], h[i-1] + 1);
				}
			}
		}
		printf("%d\n", max(f[n], max(g[n], h[n])));
	}
	return 0;
}