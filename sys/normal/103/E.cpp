#include <bits/stdc++.h>
using namespace std;

const int Maxn = 605;
int n, s, t, cnt, dis[Maxn], cur[Maxn], head[Maxn];
long long tot, ans, val[Maxn];
struct edg
{
	int nxt, to;
	long long w;
} edge[2 * Maxn * Maxn];
void add(int x, int y, long long w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0};
	head[y] = cnt;
}
queue <int> Qu;
bool bfs(void)
{
	Qu.push(s);
	memset(dis, 0, sizeof(int[2 * n + 3]));
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != s && !dis[to] && edge[i].w)
				dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[t];
}
long long dfs(int u, long long mini)
{
	if (u == t || !mini) return mini;
	long long w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && edge[i].w)
		{
			w = dfs(to, min(mini - used, edge[i].w));
			edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w, used += w;
			if (used == mini) return mini;
		}
	}
	return used;
}
void dinic(void)
{
	while (bfs())
	{
		memcpy(cur, head, sizeof(int[2 * n + 3]));
		ans += dfs(s, 0x3f3f3f3f3f3f3f3f);
	}
}
int main()
{
	scanf("%d", &n);
	s = 2 * n + 1, t = 2 * n + 2;
	for (int i = 1; i <= n; i++)
	{
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++)
		{
			int x;
			scanf("%d", &x);
			add(i, n + x, 0x3f3f3f3f3f3f3f3fLL);
		}
	}
	for (int i = 1; i <= n; i++)
		scanf("%lld", &val[i]);
	for (int i = 1; i <= 2 * n; i++)
		if (i <= n) add(s, i, 0x3f3f3f3f - val[i]), tot += 0x3f3f3f3f - val[i];
		else add(i, t, 0x3f3f3f3f);
	dinic();
	printf("%lld\n", ans - tot);
	return 0;
}