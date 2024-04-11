#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100006;
int n, q, cnt, ans, head[Maxn], fa[Maxn], siz[Maxn], pos[Maxn], bel[Maxn];
long long f[Maxn], g[Maxn];
struct edg
{
	int nxt, to, w;
}edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void dfs1(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs1(to, u);
			if (f[to] + edge[i].w >= f[u])
			{
				g[u] = f[u];
				f[u] = f[to] + edge[i].w;
			}
			else if (f[to] + edge[i].w >= g[u])
				g[u] = f[to] + edge[i].w;
		}
	}
}
void dfs2(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			if (f[u] == f[to] + edge[i].w)
			{
				if (g[u] + edge[i].w >= f[to])
				{
					g[to] = f[to];
					f[to] = g[u] + edge[i].w;
				}
				else if (g[u] + edge[i].w >= g[to])
					g[to] = g[u] + edge[i].w;
			}
			else
			{
				if (f[u] + edge[i].w >= f[to])
				{
					g[to] = f[to];
					f[to] = f[u] + edge[i].w;
				}
				else if (f[u] + edge[i].w >= g[to])
					g[to] = g[u] + edge[i].w;
			}
			dfs2(to, u);
		}
	}
}
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a == b) return ;
	fa[a] = b;
	siz[b] += siz[a];
	ans = max(ans, siz[b]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}
	dfs1(1, 0), dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		pos[i] = i;
	sort(pos + 1, pos + 1 + n, [](int x, int y){return f[x] < f[y];});
	for (int i = 1; i <= n; i++)
		bel[pos[i]] = i;
	scanf("%d", &q);
	while (q--)
	{
		long long L;
		scanf("%lld", &L);
		ans = 1;
		for (int i = 1; i <= n; i++)
			fa[i] = i, siz[i] = 1;
		int pnt = n;
		for (int u = n; u >= 1; u--)
		{
			while (f[pos[pnt]] - f[pos[u]] > L)
				siz[get_fa(pos[pnt])]--, pnt--;
			for (int i = head[pos[u]]; i; i = edge[i].nxt)
			{
				int to = edge[i].to;
				if (bel[to] > u) merge(pos[u], to);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}