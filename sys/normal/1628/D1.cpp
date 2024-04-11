#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005, p = 1e9 + 7;
int T, n, m, k;
double f[Maxn][Maxn];
bool val[Maxn][Maxn];
long long g[Maxn][Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) f[0][i] = 1e18;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				val[i][j] = (f[i - 1][j] - f[i - 1][j - 1]) / 2.0 > k;
				f[i][j] = f[i - 1][j - 1] + min((double) k, (f[i - 1][j] - f[i - 1][j - 1]) / 2.0);
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				g[i][j] = (g[i - 1][j - 1] + (val[i][j] ? k : (g[i - 1][j] - g[i - 1][j - 1] + p) * ((p + 1) / 2))) % p;
		printf("%lld\n", g[n][m]);
	}
	return 0;
}