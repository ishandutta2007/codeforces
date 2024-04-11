#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
int n, s, t, k, ct, cnt, ans, a[Maxn], c[Maxn], dis[Maxn], cur[Maxn], las[Maxn], head[Maxn], id[Maxn][2], tim[1000005];
bool vis[Maxn];
struct edg
{
	int nxt, to, w, c;
} edge[200 * Maxn];
void add(int x, int y, int w, int c)
{
	edge[++cnt] = (edg){head[x], y, w, c};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0, -c};
	head[y] = cnt;
}
queue <int> Qu;
bool SPFA(void)
{
	Qu.push(s);
	memset(dis, 0x3f, sizeof(int[ct + 1]));
	dis[s] = 0;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] > dis[u] + edge[i].c && edge[i].w)
			{
				dis[to] = dis[u] + edge[i].c;
				if (!vis[to]) Qu.push(to), vis[to] = true;
			}
		}
	}
	return dis[t] != 0x3f3f3f3f;
}
int dfs(int u, int mini)
{
	if (u == t || !mini) return mini;
	vis[u] = true;
	int w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + edge[i].c && edge[i].w && !vis[to])
		{
			w = dfs(to, min(mini - used, edge[i].w));
			used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
			if (used == mini)
			{
				vis[u] = false;
				return used;
			}
		}
	}
	vis[u] = false;
	return used;
}
void dinic(void)
{
	while (SPFA())
	{
		memcpy(cur, head, sizeof(int[ct + 1]));
		ans += dfs(s, 0x3f3f3f3f) * dis[t];
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), las[i] = tim[a[i]], tim[a[i]] = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	s = ++ct, t = ++ct;
	for (int i = 1; i <= n; i++)
	{
		id[i][0] = ++ct, id[i][1] = ++ct;
		if (i - 1) add(id[i - 1][0], id[i][0], k - 1, 0);
		add(s, id[i][0], 1, c[a[i]]), add(id[i][0], id[i][1], 1, 0), add(id[i][1], t, 1, 0);
		if (las[i]) add(id[i - 1][0], id[las[i]][1], 1, -c[a[i]]);
	}
	dinic();
	printf("%d", ans);
	return 0;
}