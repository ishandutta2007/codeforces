#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;
int T, n, m, k, a[Maxn], b[Maxn], c[Maxn], e[Maxn];
long long d[Maxn], f[Maxn];
int main()
{
	scanf("%d", &T);
	c[0] = -1;
	while (T--)
	{
		int ct1 = 0, ct2 = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
		{
			d[++ct1] = 1;
			while (a[i] % k == 0) a[i] /= k, d[ct1] *= k;
			c[ct1] = a[i];
			if (c[ct1] == c[ct1 - 1]) d[ct1 - 1] += d[ct1], ct1--;
		}
		for (int i = 1; i <= m; i++)
		{
			f[++ct2] = 1;
			while (b[i] % k == 0) b[i] /= k, f[ct2] *= k;
			e[ct2] = b[i];
			if (e[ct2] == e[ct2 - 1]) f[ct2 - 1] += f[ct2], ct2--;
		}
		if (ct1 != ct2) puts("No");
		else
		{
			for (int i = 1; i <= ct1; i++)
				if (d[i] != f[i] || c[i] != e[i])
				{
					puts("No");
					goto END;
				}
			puts("YES");
		}
		END:;
	}
	return 0;
}