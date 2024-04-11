#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int cnt, Cnt, top, ct, n, m, q, ebc, bloc[Maxn], head[Maxn], Head[Maxn], dep[Maxn], dfn[Maxn], low[Maxn], sta[Maxn], bel[Maxn], anc[Maxn][20], tag1[Maxn], tag2[Maxn];
bool vis[Maxn];
struct edg
{
	int nxt, to;
}edge[2 * Maxn], Edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void Add(int x, int y)
{
	Edge[++Cnt] = (edg){Head[x], y};
	Head[x] = Cnt;
}
void Tarjan(int u, int las_edge)
{
	dfn[u] = low[u] = ++ct;
	vis[u] = true;
	sta[++top] = u;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (((i - 1) ^ 1) + 1 == las_edge) continue;
		if (!dfn[to])
		{
			Tarjan(to, i);
			low[u] = min(low[u], low[to]);
		}
		else if (vis[to])
			low[u] = min(low[u], dfn[to]);
	}
	if (dfn[u] == low[u])
	{
		ebc++;
		int x;
		do
		{
			x = sta[top--];
			bel[x] = ebc;
			vis[x] = false;
		} while (x != u);
	}
}
void rebuild(void)
{
	for (int u = 1; u <= n; u++)
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (bel[to] != bel[u])
				Add(bel[to], bel[u]);
		}
}
void dfs(int u, int fa, int res)
{
	bloc[u] = res;
	dep[u] = dep[fa] + 1;
	anc[u][0] = fa;
	for (int i = Head[u]; i; i = Edge[i].nxt)
	{
		int to = Edge[i].to;
		if (to != fa)
		{
			dfs(to, u, res);
			tag1[u] += tag1[to];
			tag2[u] += tag2[to];
		}
	}
	if (tag1[u] && tag2[u])
	{
		printf("No");
		exit(0);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) Tarjan(1, 0);
	rebuild();
	for (int i = 1; i <= n; i++)
		if (!dep[i]) dfs(i, 0, i);
	init();
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = bel[x], y = bel[y];
		if (bloc[x] != bloc[y])
		{
			printf("No");
			return 0;
		}
		int LCA = lca(x, y);
		tag1[x]++, tag1[LCA]--, tag2[y]++, tag2[LCA]--;
	}
	memset(dep, 0, sizeof(dep));
	for (int i = 1; i <= n; i++)
		if (!dep[i]) dfs(i, 0, 0);
	printf("Yes");
	return 0;
}