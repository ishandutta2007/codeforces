/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 1005
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, t[maxn], vis[maxn];
struct edge
{
	int v, w, nxt;
}G[maxn * maxn];
int cur[maxn], adj[maxn], tot;
inline void addedge(int x, int y)
{
	G[++tot] = {y, 1, adj[x]};
	adj[x] = tot;
	G[++tot] = {x, 0, adj[y]};
	adj[y] = tot;
}
int dis[maxn];
int bfs()
{
	queue<int> q;
	dis[0] = 0;
	ru(i, 1, n + 1) dis[i] = INF;
	q.push(0);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for (int i = adj[x]; i; i = G[i].nxt)
		{
			int V = G[i].v, W = G[i].w;
			if(W && dis[V] == INF) dis[V] = dis[x] + 1, q.push(V);
		}
	}
	return dis[n + 1] != INF;
}
int dfs(int x, int flow)
{
	if(x == n + 1) return flow;
	int rem = flow;
	for (int i = cur[x]; i; i = G[i].nxt)
	{
		cur[x] = i;
		int V = G[i].v, W = G[i].w;
		if(!W || dis[V] != dis[x] + 1) continue;
		int tmp = dfs(V, min(rem, W));
		G[i].w -= tmp, G[i ^ 1].w += tmp;
		rem -= tmp;
		if(!rem) break;
	}
	return flow - rem;
}
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) vis[i] = adj[i] = 0; tot = 1;
	ru(i, 1, n) t[i] = read();
	ru(i, 1, n) if(3 * t[i] <= m) addedge(i, n + 1);
	int cnt = 0;
	ru(i, 1, n) if(3 * t[i] > m)
	{
		cnt++, addedge(0, i);
		ru(j, 1, n) if(2 * t[i] + t[j] <= m && t[i] % t[j] == 0) addedge(i, j);//, printf("%d %d\n", i, j);
	}
	int ans = 0;
	while(bfs()) 
	{
		ru(i, 0, n + 1) cur[i] = adj[i];
		ans += dfs(0, cnt);
	}
	if(ans != cnt) {printf("-1\n"); return;} 
	printf("%lld\n", n - cnt);
	for (int i = adj[0]; i; i = G[i].nxt)
	{
		int V = G[i].v;
		for (int j = adj[V]; j; j = G[j].nxt) if(!G[j].w && G[j].v)
		{
			int V2 = G[j].v;
			printf("%lld %lld\n", t[V] + t[V2], 2 * t[V] + t[V2]);
			vis[V] = vis[V2] = 1;
		}
	}
	ru(i, 1, n) if(!vis[i]) printf("%lld %lld\n", 2 * t[i], 3 * t[i]);
}
signed main()
{
	solve();
	return 0;
}