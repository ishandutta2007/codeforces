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
#define maxn 55
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, val[maxn], vis[maxn], pre[maxn];
struct Edge {int v, nxt, w, c;}G[maxn * maxn * 2];
int adj[maxn], num = 1, dis[maxn];
inline void add(int x, int y, int w, int c)
{
	G[++num] = {y, adj[x], w, c}, adj[x] = num;
	G[++num] = {x, adj[y], 0, -c}, adj[y] = num;
}
int spfa()
{
	ru(i, 2, n) dis[i] = INF;
	queue<int> q; q.push(1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for (int i = adj[x]; i; i = G[i].nxt) if(G[i].w)
		{
			int V = G[i].v;
			if(dis[V] > dis[x] + G[i].c)
			{
				dis[V] = dis[x] + G[i].c, pre[V] = i;
				if(!vis[V]) q.push(V), vis[V] = 1;
			}
		}
	}
	return dis[n] != INF;
}
int main()
{
	n = read(), m = read();
	ru(i, 1, m)
	{
		int u = read(), v = read(), w = read();
		add(u, v, 1, w); 
	}
	int lim = 0;
	while(spfa())
	{
		lim++, val[lim] = val[lim - 1];
		for (int now = n; now != 1; now = G[pre[now] ^ 1].v) G[pre[now]].w--, G[pre[now] ^ 1].w++, val[lim] += G[pre[now]].c;
//		printf("%d\n", val[lim]);
	}
	int q = read(); while(q--)
	{
		int x = read(); double ans = 1e9;
		ru(i, 1, lim) ans = min(ans, (double)(val[i] + x) / i);
		printf("%.10f\n", ans);
	}
	return 0;
}