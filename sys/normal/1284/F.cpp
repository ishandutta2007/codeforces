#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 250005;
int n, son[Maxn], dep[Maxn], Fa[Maxn], fa[Maxn], anc[Maxn][21];
vector <int> G1[Maxn], G2[Maxn];
queue <int> Qu;
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	fa[get_fa(x)] = get_fa(y);
}
void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1, anc[u][0] = f;
	for (auto to : G1[u])
		if (to != f)
			dfs1(to, u);
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
void dfs2(int u, int f)
{
	Fa[u] = f;
	for (auto to : G2[u])
		if (to != f)
			dfs2(to, u), son[u]++;
	if (!son[u]) Qu.push(u);
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) fa[i] = i;
	printf("%d\n", n - 1);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G1[x].push_back(y), G1[y].push_back(x);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G2[x].push_back(y), G2[y].push_back(x);
	}
	dfs1(1, 0), init();
	dfs2(1, 0);
	while (!Qu.empty())
	{
		int u = Qu.front();
		if (u == 1) return 0;
		Qu.pop();
		int l = lca(u, Fa[u]);
		if (dep[get_fa(u)] > dep[l])
		{
			int x = get_fa(u);
			merge(x, anc[x][0]);
			printf("%d %d %d %d\n", x, anc[x][0], u, Fa[u]);
		}
		else
		{
			int x = Fa[u];
			for (int i = 20; i >= 0; i--)
				if (dep[x] - dep[l] >= (1 << i) && get_fa(anc[x][i]) != get_fa(u)) x = anc[x][i];
			merge(x, anc[x][0]);
			printf("%d %d %d %d\n", x, anc[x][0], u, Fa[u]);
		}
		son[Fa[u]]--;
		if (!son[Fa[u]]) Qu.push(Fa[u]);
	}
}