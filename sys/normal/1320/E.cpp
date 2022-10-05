#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, q, cnt, node_ct, dfn_cnt, head[Maxn], s[Maxn], v[Maxn], u[Maxn], dfn[Maxn], dep[Maxn], node[Maxn], col[Maxn], anc[Maxn][20];
vector <int> G[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, w};
	head[y] = cnt;
}
void init_dfs(int u, int fa)
{
	dfn[u] = ++dfn_cnt;
	dep[u] = dep[fa] + 1;
	anc[u][0] = fa;
	for (auto to : G[u])
		if (to != fa) init_dfs(to, u);
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
void build(void)
{
	sort(node + 1, node + 1 + node_ct, [](int x, int y){return dfn[x] < dfn[y];});
	node_ct = unique(node + 1, node + 1 + node_ct) - node - 1;
	for (int i = node_ct - 1; i >= 1; i--)
		node[++node_ct] = lca(node[i], node[i + 1]);
	sort(node + 1, node + 1 + node_ct, [](int x, int y){return dfn[x] < dfn[y];});
	node_ct = unique(node + 1, node + 1 + node_ct) - node - 1;
	cnt = 0;
	for (int i = 1; i <= node_ct; i++) head[node[i]] = col[node[i]] = 0;
	for (int i = 1; i < node_ct; i++)
	{
		int l = lca(node[i], node[i + 1]);
		add(l, node[i + 1], dep[node[i + 1]] - dep[l]);
	}
}
struct sta
{
	int u, dis, res, id;
	bool operator < (const sta &tmp) const
	{
		return tie(dis, id, res) > tie(tmp.dis, tmp.id, tmp.res);
	}
};
priority_queue <sta> Pr;
void dijkstra(void)
{
	while (!Pr.empty())
	{
		sta now = Pr.top();
		Pr.pop();
		if (col[now.u]) continue;
		col[now.u] = now.id;
		for (int i = head[now.u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			sta tmp = now;
			tmp.res -= edge[i].w;
			if (tmp.res < 0)
			{
				int w = (-tmp.res + s[tmp.id] - 1) / s[tmp.id];
				tmp.res += w * s[tmp.id], tmp.dis += w;
			}
			Pr.push((sta){to, tmp.dis, tmp.res, tmp.id});
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	init_dfs(1, 0);
	init();
	scanf("%d", &q);
	while (q--)
	{
		int k, m;
		scanf("%d%d", &k, &m);
		node_ct = 0;
		for (int i = 1; i <= k; i++)
		{
			scanf("%d%d", &v[i], &s[i]);
			Pr.push((sta){v[i], 0, 0, i});
			node[++node_ct] = v[i];
		}
		for (int i = 1; i <= m; i++)
			scanf("%d", &u[i]), node[++node_ct] = u[i];
		build();
		dijkstra();
		for (int i = 1; i <= m; i++)
			printf("%d ", col[u[i]]);
		puts("");
	}
	return 0;
}