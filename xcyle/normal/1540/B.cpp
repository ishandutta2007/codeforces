#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define ll long long
#define maxn 405
using namespace std;
const int mo = 1e9 + 7;
int n, x, y;
int inv[maxn];
vector<int> G[maxn];
int dfn[maxn], siz[maxn], dep[maxn], tot;
int L[maxn][maxn];
int f[maxn];
void dfs(int x, int fa)
{
	f[x] = fa;
	siz[x] = 1;
	dfn[x] = ++tot; 
	dep[x] = dep[fa] + 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
		siz[x] += siz[V];
	}
}
void tpp(int x, int p, int d)
{
//	printf("!#@$#@!$ %d %d %d\n", x, p , d);
	L[p][x] = d;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == f[x]) continue;
		tpp(V, p, d);
	}
}
void work(int p, int x)
{
	L[p][x] = x;
	if(x != f[x]) work(p, f[x]);
	for (int j = 0; j < G[x].size(); j++)
	{
		int V = G[x][j];
		if(V == f[x]) continue;
		if(L[p][V]) continue;
		tpp(V, p, x);
//		printf("%$!@# %d %d %d\n", V, p, x);
	}
}
int ff[maxn][maxn];
int dp[maxn][maxn], dp1[maxn][maxn];
int main()
{
	scanf("%d", &n);
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
	}
	for (int i = n + 1; i <= 2 * n; i++)
	{
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
	}
	dp1[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp1[0][i] = (ll)dp1[0][i - 1] * inv[2] % mo;
		dp1[i][0] = (ll)dp1[0][i - 1] * inv[2] % mo;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp1[i][j] = ((ll)dp1[i - 1][j] * inv[2] % mo + (ll)dp1[i][j - 1] * inv[2] % mo) % mo;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = (dp[i][j - 1] + (ll)dp1[i - 1][j - 1] * inv[2] % mo) % mo;
//			printf("%d %d %d\n", i, j, dp[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		dep[i] = -1;
		tot = 0;
		dfs(i, i);
		memset(L, 0, sizeof(L));
		for (int j = 1; j <= n; j++)
		{
			work(j, j);
		}
		for (int j = 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
//				printf("!!! %d %d %d %d\n", i, j, k, L[j][k]);
				int tmp = ans;
				x = j, y = k;
				if(dfn[x] > dfn[y]) swap(x, y);
				if(dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + siz[x] - 1)
				{
					ans = (ans + ((x > y) ? 1 : 0)) % mo;
				}
				else
				{
					if(x < y) swap(x, y);
					ans = (ans + dp[dep[x] - dep[L[x][y]]][dep[y] - dep[L[x][y]]] % mo) % mo;
				}
				ff[j][k] = (ff[j][k] + (ans + mo - tmp) % mo) % mo;
//				printf("%d %d %d %d\n", i, j, k, (ans + mo - tmp) % mo) % mo;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
//		for (int j = i + 1; j <= n; j++) printf("%d %d %d\n", i, j, ff[i][j]);
	}
	ans = (ll)ans * inv[n] % mo;
	printf("%d", ans);
	return 0;
}