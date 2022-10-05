#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55 * 55;
int n, m, s, t, ct, head[Maxn], cnt, deg[Maxn], dis[Maxn], G[55][55], las[Maxn], flow[Maxn], from[Maxn];
bool vis[Maxn], Graph[55][55];
struct edg
{
	int nxt, to, w, c;
}edge[Maxn * 20];
void add(int x, int y, int w, int c = 0)
{
	edge[++cnt] = (edg){head[x], y, w, c};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0, -c};
	head[y] = cnt;
}
queue <int> Qu;
bool SPFA(void)
{
	queue <int> Qu;
	Qu.push(s);
	memset(dis, 0x3f, sizeof(dis));
	memset(flow, 0x3f, sizeof(flow));
	dis[s] = 0;
	while(!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		vis[u] = false;
		for(int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to, c = edge[i].c;
			if (edge[i].w && dis[to] > dis[u] + c)
			{
				dis[to] = dis[u] + c;
				from[to] = u;
				las[to] = i;
				flow[to] = min(flow[u], edge[i].w);
				if (!vis[to]) vis[to] = true, Qu.push(to);
			}
		}
	}
	return dis[t] != 0x3f3f3f3f;
}
void MCMF(void)
{
	while(SPFA())
	{
		int f = flow[t];
		int u = t;
		while(u != s)
		{
			edge[las[u]].w -= f;
			edge[((las[u] - 1) ^ 1) + 1].w += f;
			u = from[u];
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		deg[x]++;
		Graph[x][y] = true;
		G[x][y] = G[y][x] = -1;
	}
	ct = 2 * n;
	s = ++ct, t = ++ct;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (!G[i][j])
			{
				G[i][j] = G[j][i] = ++ct;
				add(s, G[i][j], 1, 0);
				add(G[i][j], i, 1, 0);
				add(G[i][j], j, 1, 0);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			add(i, i + n, 1, deg[i] + j - 1);
	for (int i = 1; i <= n; i++)
		add(i + n, t, n, 0);
	MCMF();
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (G[i][j] != -1)
				for (int k = head[G[i][j]]; k; k = edge[k].nxt)
				{
					int to = edge[k].to;
					if (to != s && !edge[k].w)
						Graph[to][i + j - to] = true;
				}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d", Graph[i][j]);
		printf("\n");
	}
	return 0;
}