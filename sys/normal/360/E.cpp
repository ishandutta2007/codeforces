#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20005;
int n, m, k, s1, s2, t, cnt, u[Maxn], v[Maxn], l[Maxn], r[Maxn], head[Maxn];
long long dis1[Maxn], dis2[Maxn];
bool vis[Maxn];
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
	long long dis;
	bool operator < (const sta &tmp) const
	{
		return dis > tmp.dis;
	}
};
priority_queue <sta> Pr;
void dijkstra(int s, long long dis[])
{
	memset(dis, 0x3f, sizeof(long long[n + 1]));
	memset(vis, 0, sizeof(bool[n + 1]));
	dis[s] = 0;
	Pr.push((sta){s, 0});
	while (!Pr.empty())
	{
		int u = Pr.top().u;
		Pr.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] > dis[u] + edge[i].w)
			{
				dis[to] = dis[u] + edge[i].w;
				Pr.push((sta){to, dis[to]});
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d%d", &n, &m, &k, &s1, &s2, &t);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d%d%d%d", &u[i], &v[i], &l[i], &r[i]);
		add(u[i], v[i], r[i]);
	}
	while (true)
	{
		bool flag = false;
		dijkstra(s1, dis1), dijkstra(s2, dis2);
		if (dis1[t] < dis2[t])
		{
			puts("WIN");
			for (int i = 1; i <= k; i++)
				printf("%d ", edge[i + m].w);
			return 0;
		}
		for (int i = 1; i <= k; i++)
			if (dis1[u[i]] < dis2[u[i]] && edge[i + m].w != l[i])
			{
				edge[i + m].w = l[i];
				flag = true;
				break;
			}
		if (!flag) break;
	}
	for (int i = 1; i <= k; i++)
		edge[i + m].w = r[i];
	while (true)
	{
		bool flag = false;
		dijkstra(s1, dis1), dijkstra(s2, dis2);
		if (dis1[t] == dis2[t])
		{
			puts("DRAW");
			for (int i = 1; i <= k; i++)
				printf("%d ", edge[i + m].w);
			return 0;
		}
		for (int i = 1; i <= k; i++)
			if (dis1[u[i]] <= dis2[u[i]] && edge[i + m].w != l[i])
			{
				edge[i + m].w = l[i];
				flag = true;
				break;
			}
		if (!flag) break;
	}
	puts("LOSE");
	return 0;
}