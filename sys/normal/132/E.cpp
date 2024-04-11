#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, m, s, t, ct, cnt, ans, top, a[Maxn], c[Maxn], las[Maxn], dis[Maxn], head[Maxn], sell[Maxn], cur[Maxn], nxt[Maxn], sta[Maxn], id[Maxn][2];
bool vis[Maxn];
map <int, int> val, tim;
struct edg
{
	int nxt, to, w, c;
} edge[20 * Maxn];
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
				if (!vis[to]) vis[to] = true, Qu.push(to);
			}
		}
	}
	return dis[t] != 0x3f3f3f3f;
}
int dfs(int u, int mini)
{
	if (u == t || !mini) return mini;
	int w, used = 0;
	vis[u] = true;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + edge[i].c && !vis[to] && edge[i].w)
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
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]), c[i] = __builtin_popcount(a[i]);
		las[i] = tim[a[i]], nxt[tim[a[i]]] = i, tim[a[i]] = i;
		id[i][0] = ++ct, id[i][1] = ++ct;
	}
	s = ++ct, t = ++ct;
	for (int i = 1; i <= n; i++)
	{
		if (i - 1) add(id[i - 1][0], id[i][0], m - 1, 0);
		add(s, id[i][0], 1, c[i]), add(id[i][0], id[i][1], 1, 0), add(id[i][1], t, 1, 0);
		if (las[i]) add(id[i - 1][0], id[las[i]][1], 1, -c[i]), sell[i] = cnt - 1;
	}
	dinic();
	int flow = 2 * n;
	for (int i = 1; i <= n; i++)
		if (sell[i] && !edge[sell[i]].w) flow--;
	printf("%d %d\n", flow, ans);
	for (int i = m - 1; i >= 0; i--)
		sta[++top] = i; 
	for (int i = 1; i <= n; i++)
	{
		if (!(sell[i] && !edge[sell[i]].w))
			printf("%c=%d\n", sta[top] + 'a', a[i]), val[a[i]] = sta[top], top--;
		printf("print(%c)\n", val[a[i]] + 'a');
		if (!(nxt[i] && !edge[sell[nxt[i]]].w)) sta[++top] = val[a[i]];
	}
	return 0;
}