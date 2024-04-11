/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, u[maxn], v[maxn], w[maxn], ch[maxn][2], tot;
int d[maxn];
set<int> G[maxn][3];
set<int>::iterator it;
int ans[maxn], vis[maxn];
void work(int t)
{
	for (int i = 1; i <= n; i++)
	{
		while(G[i][t].size() > 1)
		{
			it = G[i][t].begin();
			int x = (*it);
			it++;
			int y = (*it);
			G[i][t].erase(x), G[i][t].erase(y);
			
			int idx = (i ^ u[x] ^ v[x]), idy = (i ^ u[y] ^ v[y]);
			G[idx][t].erase(x), G[idy][t].erase(y);
			w[++tot] = t, u[tot] = idx, v[tot] = idy;
			ch[tot][0] = x, ch[tot][1] = y;
			G[idx][t].insert(tot), G[idy][t].insert(tot);
		}
	}
}
inline int tow(int id, int x)
{
	return x == u[id] ? 0 : 1;
}
void calc(int id, int tp)
{
	if(!id) return;
	ans[id] = tp;
//	printf("! %d %d %d %d\n", id, tp, ch[id][0], ch[id][1]);
	calc(ch[id][0], (tp ^ tow(ch[id][0], u[id])));
	calc(ch[id][1], (tp ^ tow(ch[id][1], v[id]) ^ 1));
}
int dep[maxn];
void dfs(int x)
{
//	if(x == 1 || x == 8) printf("!!!!\n");
	vis[x] = 1;
	for (set<int>::iterator it = G[x][1].begin(); it != G[x][1].end(); it++)
	{
		int id = (*it);
		int V = (x ^ u[id] ^ v[id]);
		if(vis[V]) continue;
		dep[V] = dep[x] ^ 1;
		dfs(V);
	}
	for (set<int>::iterator it = G[x][2].begin(); it != G[x][2].end(); it++)
	{
		int id = (*it);
		int V = (x ^ u[id] ^ v[id]);
		if(vis[V]) continue;
		dep[V] = dep[x] ^ 1;
		dfs(V);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]); 
		G[u[i]][w[i]].insert(i);
		G[v[i]][w[i]].insert(i);
		d[u[i]] ^= (w[i] & 1);
		d[v[i]] ^= (w[i] & 1);
	}
	int ans1 = 0;
	for (int i = 1; i <= n; i++) ans1 += d[i];
	printf("%d\n", ans1);
	tot = m;
	work(1), work(2);
//	for (int i = 1; i <= tot; i++)
//	{
//		ans[i] = -1;
////		printf("%d %d %d %d %d\n", i, u[i], v[i], ch[i][0], ch[i][1]);
//	}
	for (int i = 1; i <= n; i++)
	{
		if(!vis[i] && G[i][1].size() + G[i][2].size() == 1) dfs(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!vis[i]) dfs(i);
	}
	for (int x = 1; x <= n; x++)
	{
	for (set<int>::iterator it = G[x][1].begin(); it != G[x][1].end(); it++)
	{
		int id = (*it);
		if(dep[x] == 1) calc(id, tow(id, x));
		else calc(id, (tow(id, x) ^ 1)); 
//		printf("%d %d %d %d\n", id, u[id], v[id], w[id]);
	}
	for (set<int>::iterator it = G[x][2].begin(); it != G[x][2].end(); it++)
	{
		int id = (*it);
		if(dep[x] == 0) calc(id, tow(id, x));
		else calc(id, (tow(id, x) ^ 1)); 
//		printf("%d %d %d %d\n", id, u[id], v[id], w[id]);
	}
	}
	for (int i = 1; i <= m; i++) printf("%d", ans[i] + 1);
	return 0;
}