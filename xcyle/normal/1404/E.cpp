#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 205
#define N 200005
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, a[maxn][maxn];
char s[maxn];
int id[2][maxn][maxn], cnt;
struct Edge
{
	int v, nxt, w;
}G[N * 4];
int adj[N], cur[N], num = -1;
inline void add(int x, int y, int z)
{
	G[++num] = (Edge){y, adj[x], z};
	adj[x] = num;
	G[++num] = (Edge){x, adj[y], 0};
	adj[y] = num;
}
int dis[N];
queue<int> q;
int bfs()
{
	for (int i = 0; i <= cnt + 1; i++)
	{
		dis[i] = INF;
	}
	dis[0] = 0;
	q.push(0);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = adj[u]; i != -1; i = G[i].nxt)
		{
			int V = G[i].v;
//			printf("%d\n", V);
			if(!G[i].w || dis[V] != INF) continue;
			dis[V] = dis[u] + 1;
			q.push(V);
		}
	}
	return dis[cnt + 1] != INF;
}
int dfs(int x, int flow)
{
	if(x == cnt + 1)
	{
		return flow;
	}
	int rest = flow;
	for (int i = cur[x]; i != -1; i = G[i].nxt, cur[x] = i)
	{
		int V = G[i].v;
		if(dis[V] != dis[x] + 1 || !G[i].w) continue;
		int tmp = dfs(V, min(rest, G[i].w));
		G[i].w -= tmp;
		G[i ^ 1].w += tmp;
		rest -= tmp;
		if(!rest) break;
	}
	return flow - rest;
}
int main()
{
	memset(adj, -1, sizeof(adj));
	int tmp = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++)
		{
			if(s[j] == '#') a[i][j] = 1;
			else a[i][j] = 0;
			tmp += a[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(a[i][j] && a[i + 1][j]) id[0][i][j] = ++cnt;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if(a[i][j] && a[i][j + 1]) id[1][i][j] = ++cnt;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(id[0][i - 1][j] && id[1][i][j - 1]) add(id[0][i - 1][j], id[1][i][j - 1], 1);
			if(id[0][i][j] && id[1][i][j - 1]) add(id[0][i][j], id[1][i][j - 1], 1);
			if(id[0][i - 1][j] && id[1][i][j]) add(id[0][i - 1][j], id[1][i][j], 1);
			if(id[0][i][j] && id[1][i][j]) add(id[0][i][j], id[1][i][j], 1);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(a[i][j] && a[i + 1][j]) add(0, id[0][i][j], 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if(a[i][j] && a[i][j + 1]) add(id[1][i][j], cnt + 1, 1);
		}
	}
	int ans = 0;
	while(bfs())
	{
//		printf("!");
		for (int i = 0; i <= cnt + 1; i++) cur[i] = adj[i];
		ans += dfs(0, n * m);
	}
//	printf("%d %d\n", cnt, cnt - ans);
	printf("%d", tmp - (cnt - ans));
	return 0;
}