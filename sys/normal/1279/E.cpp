#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55;
int T, n, fa[Maxn], p[Maxn];
long long k, f[Maxn], fac[Maxn];
bool vis[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
}
int main()
{
	scanf("%d", &T);
	fac[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		if ((1e18 + 1) / i <= fac[i - 1]) fac[i] = 1e18 + 1;
		else fac[i] = fac[i - 1] * i;
	}
	f[0] = 1;
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= i; j++)
		{
			if ((1e18 + 1 - f[i]) / fac[max(0, j - 2)] <= f[i - j]) f[i] = 1e18 + 1;
			else f[i] += fac[max(0, j - 2)] * f[i - j];
		}
	while (T--)
	{
		scanf("%d%lld", &n, &k);
		for (int i = 1; i <= n; i++) fa[i] = i;
		memset(vis, 0, sizeof(bool[n + 1]));
		memset(p, 0, sizeof(int[n + 1]));
		int maxi = 0;
		for (int i = 1; i <= n; i++)
		{
			if (maxi == i - 1)
			{
				for (int j = 1; j <= n; j++)
					if (!vis[j])
					{
						if (k / (double) fac[max(0, j - i - 1)] > f[n - j] && k > fac[max(0, j - i - 1)] * f[n - j])
							k -= fac[max(0, j - i - 1)] * f[n - j];
						else
						{
							maxi = p[i] = j, merge(i, j), vis[j] = true;
							break;
						}
					}
			}
			else
			{
				for (int j = 1; j <= n; j++)
					if (!vis[j] && (get_fa(j) != get_fa(i) || i == maxi))
					{
						if (k / (double) fac[max(0, maxi - i - 1)] > f[n - maxi] && k > fac[max(0, maxi - i - 1)] * f[n - maxi])
							k -= fac[max(0, maxi - i - 1)] * f[n - maxi];
						else
						{
							p[i] = j, merge(i, j), vis[j] = true;
							break;
						}
					}
			}
		}
		for (int i = 1; i <= n; i++)
			if (!p[i])
			{
				puts("-1");
				goto END;
			}
		if (k != 1) puts("-1");
		else
		{
			for (int i = 1; i <= n; i++)
				printf("%d ", p[i]);
			puts("");
		}
		END:;
	}
	return 0;
}