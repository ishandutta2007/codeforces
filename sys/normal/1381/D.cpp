#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a, b, cnt, len, root, dep[Maxn], head[Maxn], anc[Maxn][20];
pair <pair <int, int>, pair <int, int> > maxi[Maxn];
bool vis[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void merge(pair <pair <int, int>, pair <int, int> > & x, pair <int, int> y)
{
	if (dep[y.first] > dep[x.first.first])
	{
		if (x.first.second != y.second) x.second = x.first;
		x.first = y;
	}
	else if (y.second != x.first.second && dep[y.first] > dep[x.second.first])
		x.second = y;
}
void init_dfs(int u, int fa)
{
	maxi[u] = make_pair(make_pair(u, 0), make_pair(0, 0));
	anc[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			init_dfs(to, u);
			merge(maxi[u], make_pair(maxi[to].first.first, to));
		}
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
int kth_anc(int x, int k)
{
	for (int i = 19; i >= 0; i--)
		if (k & (1 << i)) x = anc[x][i];
	return x;
}
void dfs(int u, int fa, int d)
{
	int ct = 0;
	if (dep[maxi[u].second.first] - dep[u] >= len && d >= len)
	{
		root = u;
		return ;
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u, max((to == maxi[u].first.second ? dep[maxi[u].second.first] : dep[maxi[u].first.first]) - dep[u], d) + 1);
			if (dep[maxi[to].first.first] - dep[u] >= len) ct++;
			if (root) return ;
		}
	}
	if (ct >= 3) root = u;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &a, &b);
		root = cnt = 0;
		memset(head, 0, sizeof(int[n + 1]));
		memset(vis, 0, sizeof(bool[n + 1]));
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		init_dfs(1, 0);
		init();
		len = dep[a] + dep[b] - 2 * dep[lca(a, b)];
		dfs(1, 0, 0);
		if (!root)
		{
			puts("NO");
			continue;
		}
		init_dfs(root, 0);
		init();
		while (true)
		{
			swap(a, b);
			int delta = -dep[a];
			a = maxi[a].first.first;
			delta += dep[a];
			b = kth_anc(b, delta);
			if (vis[a] || vis[b])
			{
				puts("NO");
				goto END;
			}
			vis[a] = true, vis[b] = true;
			if (lca(a, b) == b)
			{
				puts("YES");
				goto END;
			}
		}
		puts("NO");
		END:;
	}
	return 0;
}