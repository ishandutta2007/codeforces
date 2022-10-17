#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 12005
#define maxm 400005
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, g, st[maxn];
int type, value, k, tmp, flag;
char s[maxn];
int ans = 0;
struct Edge
{
	int v, nxt, w;
}G[maxm];
int adj[maxn], num = -1, cur[maxn];
inline void add(int x, int y, int z)
{
	G[++num] = (Edge){y, adj[x], z};
	adj[x] = num;
	G[++num] = (Edge){x, adj[y], 0};
	adj[y] = num;
}
int dis[maxn];
queue<int> q;
int bfs()
{
	for (int i = 1; i <= n + m + 1; i++)
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
			if(!G[i].w || dis[V] != INF) continue;
			dis[V] = dis[u] + 1;
			q.push(V);
		}
	}
	return dis[n + m + 1] != INF;
}
int dfs(int x, int flow)
{
	if(x == n + m + 1) return flow;
	int rest = flow;
	for (int i = cur[x]; i != -1; i = G[i].nxt)
	{
		cur[x] = i;
		int V = G[i].v;
		if(!G[i].w || dis[V] != dis[x] + 1) continue;
		int temp = dfs(V, min(rest, G[i].w));
		rest -= temp;
		G[i].w -= temp;
		G[i ^ 1].w += temp;
		if(!rest) break; 
	}
	return flow - rest;
}
int main()
{
	memset(adj, -1, sizeof(adj));
	scanf("%d%d%d", &n, &m, &g);
	for (int i = 1; i <= n; i++) scanf("%d", &st[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		if(st[i] == 0)
		{
			add(0, i, 0);
			add(i, n + m + 1, tmp);
		}
		else
		{
			add(0, i, tmp);
			add(i, n + m + 1, 0);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &type, &value, &k);
		ans += value;
		for (int j = 1; j <= k; j++)
		{
			scanf("%d", &tmp);
			if(type == 0) add(tmp, n + i, INF);
			else add(n + i, tmp, INF);
		}
		scanf("%d", &flag);
		if(flag == 0)
		{
			if(type == 0) add(n + i, n + m + 1, value);
			else add(0, n + i, value);
		}
		else
		{
			if(type == 0) add(n + i, n + m + 1, value + g);
			else add(0, n + i, value + g);
		}
	}
	while(bfs())
	{
		for (int i = 0; i <= n + m + 1; i++) cur[i] = adj[i];
		ans -= dfs(0, INF);
	}
	printf("%d", ans);
	return 0;
}