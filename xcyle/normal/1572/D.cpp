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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 8005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[1 << 20], vis[1 << 20], ans; pii v[1 << 20];
struct Edge
{
	int v, nxt, w, c;
}G[maxn * 100];
int dis[maxn], adj[maxn], num = 1, cur[maxn];
inline void add(int x, int y, int z, int c)
{
//	printf("%d %d %d %d\n", x, y, z, c);
	G[++num] = {y, adj[x], z, c}, adj[x] = num;
	G[++num] = {x, adj[y], 0, -c}, adj[y] = num;
}
queue<int> q;
void spfa()
{
	ru(i, 0, 2 * n * k + 1) dis[i] = INF, cur[i] = adj[i], vis[i] = 0;
	dis[0] = 0, q.push(0);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
//		printf("%d %d\n", x, dis[x]);
		vis[x] = 0;
		for (int i = adj[x]; i; i = G[i].nxt)
		{
			int V = G[i].v;
			if(!G[i].w || dis[V] <= dis[x] + G[i].c) continue;
			dis[V] = dis[x] + G[i].c;
			if(!vis[V]) vis[V] = 1, q.push(V);
		}
	}
//	ru(i, 0, 2 * n * k + 1) printf("%d %d\n", i, dis[i]); 
}
int dfs(int x, int flow)
{
//	printf("%d %d\n", x, flow);
	if(x == 2 * n * k + 1) return flow;
	int rest = flow;
	vis[x] = 1;
	for (int i = cur[x]; i; i = G[i].nxt)
	{
		cur[x] = i;
		int V = G[i].v;
		if(!G[i].w || vis[V] || dis[V] != dis[x] + G[i].c) continue;
		int tmp = dfs(V, min(rest, G[i].w));
		ans -= tmp * G[i].c;
		G[i].w -= tmp, G[i ^ 1].w += tmp, rest -= tmp;
		if(!rest) break;
	}
	vis[x] = 0;
	return flow - rest;
}
int main()
{
	n = read(), k = min(read(), (1 << (n - 1)));
	ru(i, 0, (1 << n) - 1) a[i] = read();
	ru(i, 0, (1 << n) - 1)
	{
		int res = 0;
		ru(j, 0, n - 1) res = max(res, a[i ^ (1 << j)]);
		v[i] = mp(res + a[i], i);
	}
	sort(v, v + (1 << n), [](pii x, pii y){return x > y;});
	ru(i, 0, min((1 << n), 2 * n * k) - 1) 
	{
		int x = v[i].se;
		vis[x] = i + 1;
		if(__builtin_popcount(x) & 1) add(0, i + 1, 1, -a[x]);
		else add(i + 1, 2 * n * k + 1, 1, -a[x]); 
	}
	ru(i, 0, (1 << n) - 1) if(vis[i] && (__builtin_popcount(i) & 1)) ru(j, 0, n - 1) if(vis[i ^ (1 << j)]) add(vis[i], vis[i ^ (1 << j)], 1, 0);
	memset(vis, 0, sizeof(vis));
	ru(i, 1, k) spfa(), dfs(0, 1);
	printf("%d\n", ans);
	return 0;
}