#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
int n, m, s, t, ct, cnt, ans, tot, x[Maxn], y[Maxn], w[Maxn], resx[Maxn], resy[Maxn], resw[Maxn], head[Maxn], cur[Maxn], dis[Maxn];
bool vis[Maxn], vis2[Maxn];
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
void rebuild(void)
{
	cnt = 0;
	memset(head, 0, sizeof(int[n + 1]));
	for (int i = 1; i <= m; i++)
		add(resx[i], resy[i], resw[i]);
}
queue <int> Qu;
bool bfs(void)
{
	Qu.push(s);
	memset(dis, 0, sizeof(int[n + 1]));
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
	if (u == t || !mini) return mini;
	int w, used = 0;
	for (int &i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && edge[i].w)
		{
			w = dfs(to, min(mini - used, edge[i].w));
			edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w, used += w;
			if (used == mini) return used;
		}
	}
	return used;
}
void dinic(void)
{
	while (bfs())
	{
		memcpy(cur, head, sizeof(int[n + 1]));
		ans += dfs(s, 0x3f3f3f3f);
	}
	tot += ans;
}
void redfs(int u, vector <int> &V)
{
	vis2[u] = true;
	if (vis[u]) V.push_back(u);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (edge[i].w && !vis2[to])
			redfs(to, V);
	}
}
void work(vector <int> Ve)
{
	vector <int> Ve1, Ve2;
	if (Ve.size() <= 1) return ;
	s = Ve[0], t = Ve[1];
	rebuild();
	memset(vis, 0, sizeof(bool[n + 1]));
	for (vector <int> :: iterator it = Ve.begin(); it != Ve.end(); it++)
		vis[*it] = true;
	ans = 0;
	dinic();
	x[++ct] = s, y[ct] = t, w[ct] = ans;
	G[x[ct]].push_back(ct), G[y[ct]].push_back(ct);
	memset(vis2, 0, sizeof(bool[n + 1]));
	redfs(s, Ve1);
	for (vector <int> :: iterator it = Ve.begin(); it != Ve.end(); it++)
		if (!vis2[*it]) Ve2.push_back(*it);
	work(Ve1), work(Ve2);
}
void redfs2(int u, int fa, vector <int> &V)
{
	vis2[u] = true;
	for (vector <int> :: iterator it = G[u].begin(); it != G[u].end(); it++)
	{
		int to = u == x[*it] ? y[*it] : x[*it];
		if (vis[to] && to != fa)
		{
			V.push_back(*it);
			redfs2(to, u, V); 
		}
	}
}
void print(vector <int> Ve)
{
	if (!Ve.size()) return ;
	if (Ve.size() == 1)
	{
		printf("%d %d ", x[Ve[0]], y[Ve[0]]);
		return ;
	}
	vector <int> Ve1, Ve2;
	int mini = 0x3f3f3f3f;
	memset(vis, 0, sizeof(bool[n + 1]));
	for (vector <int> :: iterator it = Ve.begin(); it != Ve.end(); it++)
		mini = min(mini, w[*it]), vis[x[*it]] = true, vis[y[*it]] = true;
	for (vector <int> :: iterator it = Ve.begin(); it != Ve.end(); it++)
		if (w[*it] == mini)
		{
			redfs2(x[*it], y[*it], Ve1);
			redfs2(y[*it], x[*it], Ve2);
			if (Ve1.size()) print(Ve1);
			else printf("%d ", x[*it]);
			if (Ve2.size()) print(Ve2);
			else printf("%d ", y[*it]);
			return ;
		}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &resx[i], &resy[i], &resw[i]);
	vector <int> tmp;
	for (int i = 1; i <= n; i++)
		tmp.push_back(i);
	work(tmp);
	tmp.pop_back();
	printf("%d\n", tot);
	print(tmp);
	return 0;
}