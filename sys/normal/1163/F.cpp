#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, q, cnt, x[Maxn], y[Maxn], w[Maxn], dep[Maxn], head[Maxn], from[Maxn], e[Maxn], anc[Maxn][20];
long long dis1[Maxn], dis2[Maxn], mini[Maxn][20];
bool vis[Maxn];
vector <int> Ve[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
struct sta
{
	int u;
	long long w;
	bool operator < (const sta &tmp) const
	{
		return w > tmp.w;
	}
};
priority_queue <sta> Pr;
void dijkstra(int s, long long dis[])
{
	memset(dis, 0x3f, sizeof(long long[n + 1]));
	dis[s] = 0;
	Pr.push((sta){s, 0});
	while (!Pr.empty())
	{
		int u = Pr.top().u;
		Pr.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] > dis[u] + edge[i].w)
			{
				dis[to] = dis[u] + edge[i].w;
				if (s == 1)
				{
					from[to] = u;
					e[to] = i;
				}
				Pr.push((sta){to, dis[to]});
			}
		}
	}
}
void dfs(int u)
{
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
		dep[*it] = dep[u] + 1, anc[*it][0] = u, dfs(*it);
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
void modify(int x, int y, long long w)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) mini[x][i] = min(mini[x][i], w), x = anc[x][i];
}
void work(void)
{
	for (int j = 19; j >= 0; j--)
		for (int i = 1; i <= n; i++)
		{
			mini[i][j - 1] = min(mini[i][j - 1], mini[i][j]);
			mini[anc[i][j - 1]][j - 1] = min(mini[anc[i][j - 1]][j - 1], mini[i][j]);
		}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		add(x[i], y[i], w[i]), add(y[i], x[i], w[i]);
	}
	dijkstra(1, dis1), dijkstra(n, dis2);
	int tmp = n;
	while (tmp != 1)
	{
		vis[(e[tmp] + 1) >> 1] = true;
		tmp = from[tmp];
	}
	for (int i = 2; i <= n; i++)
		Ve[from[i]].push_back(i);
	dfs(1);
	init();
	memset(mini, 0x3f, sizeof(mini));
	for (int i = 1; i <= m; i++)
		if (!vis[i])
		{
			int l1 = lca(x[i], n), l2 = lca(y[i], n);
			modify(l1, l2, min(dis1[x[i]] + w[i] + dis2[y[i]], dis1[y[i]] + w[i] + dis2[x[i]]));
		}
	work();
	while (q--)
	{
		int t, d;
		scanf("%d%d", &t, &d);
		if (!vis[t])
		{
			printf("%lld\n", min(dis1[n], min(dis1[x[t]] + d + dis2[y[t]], dis1[y[t]] + d + dis2[x[t]])));
			continue;
		}
		if (w[t] > d)
		{
			printf("%lld\n", dis1[n] - w[t] + d);
			continue;
		}
		if (dep[x[t]] < dep[y[t]]) swap(x[t], y[t]);
		printf("%lld\n", min(dis1[n] - w[t] + d, mini[x[t]][0]));
	}
	return 0;
}