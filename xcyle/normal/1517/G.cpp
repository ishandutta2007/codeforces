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
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 2005
using namespace std;
const ll INF = 1e15;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, x[maxn], y[maxn], w[maxn], tot;
map<pii, int> id;
struct edge
{
	int v, nxt; ll w;
}G[maxn * 100];
int adj[maxn], cur[maxn], dis[maxn], num = 1;
inline void add(int x, int y, ll z)
{
	G[++num] = {y, adj[x], z}, adj[x] = num;
	G[++num] = {x, adj[y], 0}, adj[y] = num;
}
queue<int> q;
int bfs()
{
	ru(i, 0, 2 * n + 1) dis[i] = 0x3f3f3f3f;
	dis[0] = 0, q.push(0);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for (int i = adj[x]; i; i = G[i].nxt) if(G[i].w && dis[G[i].v] == 0x3f3f3f3f)
		{
			dis[G[i].v] = dis[x] + 1, q.push(G[i].v);
		}
	}
	return dis[2 * n + 1] != 0x3f3f3f3f;
}
ll dfs(int x, ll flow)
{
	if(x == 2 * n + 1) return flow;
	ll rest = flow;
	for (int i = cur[x]; i; i = G[i].nxt)
	{
		cur[x] = i;
		int V = G[i].v;
		if(!G[i].w || dis[V] != dis[x] + 1) continue;
		ll tmp = dfs(V, min(rest, G[i].w));
		G[i].w -= tmp, G[i ^ 1].w += tmp, rest -= tmp;
		if(!rest) break;
	}
	return flow - rest;
}
int main()
{
	n = read();
	ll ans = 0;
	ru(i, 1, n)
	{
		x[i] = read(), y[i] = read(), w[i] = read(), ans += w[i];
		id[mp(x[i], y[i])] = ++tot;
		if(x[i] & 1)
		{
			if(y[i] & 1) add(0, tot, w[i]);
			else add(tot, n * 2 + 1, w[i]);
		}
		else tot++, add(tot - 1, tot, w[i]);
	}
	ru(i, 1, n) if(x[i] % 2 == 0)
	{
		if(y[i] & 1)
		{
			if(id[mp(x[i] - 1, y[i])]) add(id[mp(x[i] - 1, y[i])], id[mp(x[i], y[i])], INF);
			if(id[mp(x[i] + 1, y[i])]) add(id[mp(x[i] + 1, y[i])], id[mp(x[i], y[i])], INF);
			if(id[mp(x[i], y[i] + 1)]) add(id[mp(x[i], y[i])] + 1, id[mp(x[i], y[i] + 1)], INF);
			if(id[mp(x[i], y[i] - 1)]) add(id[mp(x[i], y[i])] + 1, id[mp(x[i], y[i] - 1)], INF);
		}
		else
		{
			if(id[mp(x[i] - 1, y[i])]) add(id[mp(x[i], y[i])] + 1, id[mp(x[i] - 1, y[i])], INF);
			if(id[mp(x[i] + 1, y[i])]) add(id[mp(x[i], y[i])] + 1, id[mp(x[i] + 1, y[i])], INF);
		}
	}
	while(bfs())
	{
		ru(i, 0, 2 * n + 1) cur[i] = adj[i];
		ans -= dfs(0, INF);
	}
	printf("%lld\n", ans);
	return 0;
}