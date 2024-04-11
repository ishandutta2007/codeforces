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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, fa[maxn], anc[maxn][22];
vector<int> G[maxn], val[maxn];
int dep[maxn], f[maxn], dfn[maxn], tot, siz[maxn];
int u[maxn], v[maxn], x[maxn];
inline int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int t[maxn];
void dfs(int x, int fat)
{
	anc[x][0] = fat;
	for (int i = 1; i <= 20; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	dfn[x] = ++tot;
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fat) continue;
		dep[V] = dep[x] + 1, f[V] = f[x] ^ val[x][i];
		dfs(V, x);
		siz[x] += siz[V];
	}
}
inline int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) if(dep[anc[y][i]] >= dep[x]) y = anc[y][i];
	if(x == y) return x;
	for (int i = 20; i >= 0; i--) if(anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
inline void add(int x, int d)
{
	for (; x <= n; x += x & -x) t[x] += d;
}
inline int que(int x)
{ 
	x = dfn[x];
	int res = 0;
	for (; x; x -= x & -x) res += t[x];
	return res;
} 
void work(int x, int y)
{
	if(x == y) return;
	if(dep[x] > dep[y]) swap(x, y);
	add(dfn[y], 1), add(dfn[y] + siz[y], -1);
	work(x, anc[y][0]);
}
int main()
{
	n = read(), q = read();
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= q; i++)
	{
		u[i] = read(), v[i] = read(), x[i] = read();
		int fu = find(u[i]), fv = find(v[i]);
		if(fu == fv) continue;
		else
		{
			G[u[i]].push_back(v[i]), G[v[i]].push_back(u[i]);
			val[u[i]].push_back(x[i]), val[v[i]].push_back(x[i]);
			u[i] = -1;
			fa[fu] = fv;
		}
	}
	for (int i = 1; i <= n; i++) if(!dfn[i]) dfs(i, i);
	for (int i = 1; i <= q; i++)
	{
		if(u[i] == -1 || f[u[i]] ^ f[v[i]] ^ x[i] != 1) continue;
		int tmp = que(u[i]) + que(v[i]) - 2 * que(lca(u[i], v[i]));
		if(!tmp) work(u[i], v[i]), u[i] = -1;
	}
	for (int i = 1; i <= q; i++) u[i] == -1 ? printf("YES\n") : printf("NO\n");
	return 0;
}