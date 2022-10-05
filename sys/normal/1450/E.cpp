#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
int n, m, ans = -1, pos, x[10 * Maxn], y[10 * Maxn], G[Maxn][Maxn];
int main()
{
	scanf("%d%d", &n, &m);
	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= n; i++) G[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int type;
		scanf("%d%d%d", &x[i], &y[i], &type);
		G[x[i]][y[i]] = 1;
		if (type) G[y[i]][x[i]] = -1;
		else G[y[i]][x[i]] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	for (int i = 1; i <= n; i++)
	{
		if (G[i][i] < 0)
		{
			puts("NO");
			return 0;
		}
		for (int j = 1; j <= m; j++)
			if (G[i][x[j]] == G[i][y[j]])
			{
				puts("NO");
				return 0;
			}
		int maxi = 0;
		for (int j = 1; j <= n; j++)
			maxi = max(maxi, G[i][j]);
		if (maxi > ans) ans = maxi, pos = i;
	}
	puts("YES");
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		printf("%d ", G[pos][i] + n);
	return 0;
}