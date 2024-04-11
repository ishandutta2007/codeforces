#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 2005;
int n, m, s, t, cnt, x[Maxn], y[Maxn], dis[Maxn], head[Maxn], cur[Maxn], a[Maxn];
bool vis[Maxn];
vector <int> G[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0};
	head[y] = cnt;
}
queue <int> Qu;
bool bfs(void)
{
	memset(dis, 0, sizeof(int[n + 3]));
	Qu.push(s);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!dis[to] && to != s && edge[i].w) dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[t];
}
int dfs(int u, int mini)
{
	if (!mini || u == t) return mini;
	int w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && edge[i].w)
		{
			w = dfs(to, min(mini - used, edge[i].w));
			used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
			if (used == mini) return used;
		}
	}
	return used;
}
void dinic(void)
{
	while (bfs())
	{
		memcpy(cur, head, sizeof(int[n + 3]));
		dfs(s, 0x3f3f3f3f);
	}
}
void work(int L, int R, vector <int> Ve)
{
	if (L == R || Ve.size() <= 1) return ;
	int mid = (L + R) >> 1;
	memset(head, 0, sizeof(int[n + 3]));
	cnt = 0;
	for (auto u : Ve)
	{
		vis[u] = true;
		if (a[u] <= mid) add(u, t, 1);
		else add(s, u, 1);
	}
	for (int i = 1; i <= m; i++)
		if (vis[x[i]] && vis[y[i]])
			add(x[i], y[i], 0x3f3f3f3f);
	memset(vis, 0, sizeof(bool[n + 3]));
	dinic();
	for (int i = head[s]; i; i = edge[i].nxt)
		if (edge[i].w) Qu.push(edge[i].to), vis[edge[i].to] = true;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!vis[to] && edge[i].w) Qu.push(to), vis[to] = true;
		}
	}
	vector <int> V1, V2;
	for (auto u : Ve)
		if (vis[u]) a[u] = max(a[u], mid + 1), V2.push_back(u);
		else a[u] = min(a[u], mid), V1.push_back(u);
	work(L, mid, V1), work(mid + 1, R, V2);
}
int main()
{
	scanf("%d%d", &n, &m);
	s = n + 1, t = n + 2;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &x[i], &y[i]), G[x[i]].push_back(y[i]);
	vector <int> V;
	for (int i = 1; i <= n; i++)
		V.push_back(i);
	work(1, 1e9, V);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}