#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 3005
#define int long long
using namespace std;
int n, u, v;
int fa[maxn][maxn], siz[maxn][maxn];
int f[maxn][maxn];
vector<int> G[maxn];
void dfs(int s, int x, int fat)
{
	fa[s][x] = fat;
	siz[s][x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fat) continue;
		dfs(s, V, x);
		siz[s][x] += siz[s][V];
	}
}
int work(int x, int y)
{
//	printf("%d %d\n", x, y);
	if(f[x][y]) return f[x][y];
	if(x == y) return 0;
	f[x][y] = max(work(fa[y][x], y), work(x, fa[x][y])) + siz[y][x] * siz[x][y];
	return f[x][y];
}
signed main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, i, i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(!f[i][j]) work(i, j); 
			ans = max(ans, f[i][j]);
		}
	}
	printf("%lld", ans);
	return 0;
}