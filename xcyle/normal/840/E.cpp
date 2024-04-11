#include <iostream>
#include <cstdio>
#include <vector>
#define A 8
#define B 8
#define maxn 50005
using namespace std;
int n, q, u, v, a[maxn], fa[maxn], anc[maxn], dep[maxn];
vector<int> G[maxn];
int dp[maxn][(1 << 8)], need[maxn][1 << 8];//x8triei 
void dfs(int x)
{
	int p = x;
	for (int i = 0; i < (1 << A); i++) dp[x][i] = -1;
	for (int i = 0; i < (1 << B); i++)
	{
		dp[x][a[p] >> B] = max(dp[x][a[p] >> B], ((a[p] % (1 << B)) ^ i));
		p = fa[p];
	}
	anc[x] = p;
	for (int i = (1 << A) - 1; i >= 0; i--)
	{
		if(dp[x][i] == -1) continue;
		need[x][0] = i;
		break;
	}
	for (int i = 0; i < (1 << A); i++)
	{
		for (int j = 0; j < A; j++)
		{
			if((i >> j) & 1)
			{
				int p = need[x][i ^ (1 << j)] & ((1 << A) - (1 << (j + 1)));
				for (register int k = (1 << (j + 1)) - 1; k >= 0; k--)
				{
					if(dp[x][p + ((i % (1 << (j + 1))) ^ k)] == -1) continue;
					need[x][i] = p + ((i % (1 << (j + 1))) ^ k);
//					printf("%d %d %d\n", x, i, need[x][i]);
					break;
				}
				break;
			}
		} 
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa[x]) continue;
		fa[V] = x;
		dep[V] = dep[x] + 1;
		dfs(V); 
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &u, &v);
		int p = v;
		int ans = (a[u] ^ (dep[v] - dep[u]));
		for (register int j = 0; j < (1 << A); j++)
		{
			if(dep[p] - dep[u] <= (1 << B)) break;
			ans = max(ans, dp[p][need[p][j]] + (1 << B) * (need[p][j] ^ j));
			p = anc[p];
		}
		for (; p != u; p = fa[p]) ans = max(ans, (a[p] ^ (dep[v] - dep[p])));
		printf("%d\n", ans);
	}
	return 0;
}