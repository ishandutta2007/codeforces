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
#define maxn 10005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, GG[55][55], tot;
struct Edge
{
	int v, nxt, w, c;
}G[maxn * 1000];
int adj[maxn], num = 1, cur[maxn];
void add(int a, int b, int c, int d)
{
	G[++num] = {b, adj[a], c, d}, adj[a] = num;
	G[++num] = {a, adj[b], 0, -d}, adj[b] = num;
}
int dis[maxn], vis[maxn];
queue<int> q;
int spfa()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i <= tot; i++) dis[i] = INF;
	dis[0] = 0, q.push(0);
	while(!q.empty())
	{
		int u = q.front();
		vis[u] = 0;
		q.pop();
		for (int i = adj[u]; i; i = G[i].nxt)
		{
			int V = G[i].v;
			if(!G[i].w) continue;
			if(dis[V] > dis[u] + G[i].c)
			{
				dis[V] = dis[u] + G[i].c;
				if(!vis[V])
				{
					vis[V] = 1;
					q.push(V);
				}
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	ru(i, 0, tot) cur[i] = adj[i];
	return dis[tot] != INF;
}
int dfs(int x, int flow)
{
	if(x == tot) return flow;
	vis[x] = 1;
	int rest = flow, V, tmp;
	for (int i = cur[x]; i; i = G[i].nxt)
	{
		cur[x] = i;
		V = G[i].v;
		if(vis[V] || !G[i].w || dis[V] != dis[x] + G[i].c) continue;
		tmp = dfs(V, min(rest, G[i].w));
		rest -= tmp;
		G[i].w -= tmp;
		G[i ^ 1].w += tmp;
		if(!rest) break;
	}
	vis[x] = 0;
	return flow - rest;
}
int main()
{
	n = read(), m = read(); tot = n;
	ru(i, 1, m) GG[read()][read()] = 1;
	ru(i, 1, n) ru(j, i + 1, n) if(!GG[i][j] && !GG[j][i])
	{
		tot++, add(0, tot, 1, 0), add(tot, i, 1, 0), add(tot, j, 1, 0);
	}
	tot++;
	ru(i, 1, n)
	{
		int cnt = 0;
		ru(j, 1, n) cnt += GG[i][j];
		ru(j, cnt + 1, n) add(i, tot, 1, j);
	}
	while(spfa()) dfs(0, INF);
	int tmp = n;
	ru(i, 1, n) ru(j, i + 1, n) if(!GG[i][j] && !GG[j][i])
	{
		tmp++;
		for (int k = adj[tmp]; k; k = G[k].nxt)
		{
			if(G[k].v <= n && !G[k].w) GG[G[k].v][G[k].v ^ i ^ j] = 1;
		}
	}
	ru(i, 1, n) {ru(j, 1, n) printf("%d", GG[i][j]); printf("\n");}
	return 0;
}