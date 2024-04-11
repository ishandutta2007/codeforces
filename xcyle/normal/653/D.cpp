/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1005
#define double long double
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-12;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, x, a[maxn], b[maxn], c[maxn];
struct Edge
{
	int v, nxt, w;;
}G[maxn * 2];
int adj[maxn], cur[maxn], tot;
void add(int x, int y, int z)
{
	G[++tot] = {y, adj[x], z};
	adj[x] = tot;
	G[++tot] = {x, adj[y], 0};
	adj[y] = tot;
}
int dis[maxn], vis[maxn];
queue<int> q;
int bfs()
{
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[1] = 0;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		vis[u] = 0;
		q.pop();
		for (int i = adj[u]; i != -1; i = G[i].nxt)
		{
			int V = G[i].v;
			if(G[i].w && dis[V] > dis[u] + G[i].w)
			{
				dis[V] = dis[u] + G[i].w;
				if(!vis[V]) q.push(V), vis[V] = 1;
			} 
		}
	}
	return dis[n] != INF;
}
int dfs(int x, int flow)
{
	if(x == n) return flow;
	int rest = flow;
	for (int i = cur[x]; i != -1; i = G[i].nxt)
	{
		cur[x] = i;
		int V = G[i].v;
		if(!G[i].w || dis[V] != dis[x] + G[i].w) continue;
		int tmp = dfs(V, min(G[i].w, rest));
		rest -= tmp;
		G[i].w -= tmp;
		G[i ^ 1].w += tmp;
	}
	return flow - rest;
}
int check(double t)
{
	for (int i = 0; i <= n + 1; i++) adj[i] = -1;
	tot = -1;
	for (int i = 1; i <= m; i++)
	{
		if(t * x <= c[i]) add(a[i], b[i], x);
		else add(a[i], b[i], (double)c[i] / t);
	}
	int ans = 0;
	while(bfs())
	{
		for (int i = 0; i <= n + 1; i++) cur[i] = adj[i];
		ans += dfs(1, x);
		if(ans >= x) break;
	}
	return ans >= x;
}
signed main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	double l = 0.0, r = 1000000000.0, mid;
	while(r - l > eps)
	{
		mid = (l + r + eps) / 2.0;
		if(check(mid)) l = mid;
		else r = mid - eps;
//		printf("%.9f %.9f %.9f\n", l, mid, r);
	}
	printf("%.9Lf", l * x);
	return 0;
}