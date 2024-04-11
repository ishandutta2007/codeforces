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
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, e[maxn], val[maxn], jump[maxn][22], ch[maxn][2];
int fa[maxn], mn[maxn], mx[maxn], dep[maxn], dfn[maxn], tot, ans[maxn][2];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
struct node
{
	int a, b, c, t;
}p[maxn];
inline bool cmp1(node x, node y){return x.c == y.c ? x.t > y.t : x.c > y.c;}
inline bool cmp2(node x, node y){return x.t < y.t;}
inline void dfs(int x)
{
	if(!x) return;
	dfn[x] = ++tot, dep[ch[x][0]] = dep[ch[x][1]] = dep[x] + 1;
	dfs(ch[x][0]), dfs(ch[x][1]);
}
inline int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) if(dep[jump[y][i]] >= dep[x]) y = jump[y][i];
	if(x == y) return val[x];
	for (int i = 20; i >= 0; i--) if(jump[x][i] != jump[y][i]) x = jump[x][i], y = jump[y][i];
	return val[jump[x][0]];
}
int main()
{
	n = read(), q = read();
	for (int i = 1; i <= n; i++) e[i] = read();
	for (int i = 1; i < n; i++) p[i].a = read(), p[i].b = read(), p[i].c = read(), p[i].t = read();
	sort(p + 1, p + n, cmp2);
	for (int i = 1; i < 2 * n; i++) fa[i] = i;
	for (int i = 1; i < n; i++)
	{
		val[n + i] = p[i].t;
		int ta = find(p[i].a), tb = find(p[i].b); ch[n + i][0] = ta, ch[n + i][1] = tb;
		jump[ta][0] = jump[tb][0] = fa[ta] = fa[tb] = n + i;
	}
	for (int i = 2 * n - 1; i >= 1; i--) for (int j = 1; j < 20; j++) jump[i][j] = jump[jump[i][j - 1]][j - 1];
	dfs(2 * n - 1); dep[0] = 0;
	for (int i = 1; i <= n; i++) fa[i] = mn[i] = mx[i] = i;
	for (int i = 1; i <= q; i++)
	{
		int v = read(), x = read();
		p[n + i - 1] = {x, i, v, -1};
	}
	sort(p + 1, p + n + q, cmp1);
	for (int i = 1; i < n + q; i++)
	{
		if(p[i].t == -1)
		{
			int bel = find(p[i].a);
			ans[p[i].b][0] = e[bel];
			ans[p[i].b][1] = max(lca(mn[bel], p[i].a), lca(p[i].a, mx[bel]));
		}
		else
		{
			int ta = find(p[i].a), tb = find(p[i].b);
			if(e[ta] < e[tb]) swap(ta, tb);
			fa[tb] = ta;
			if(e[ta] == e[tb])
			{
				if(dfn[mn[ta]] > dfn[mn[tb]]) mn[ta] = mn[tb];
				if(dfn[mx[ta]] < dfn[mx[tb]]) mx[ta] = mx[tb];
			}
		}
	}
	for (int i = 1; i <= q; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}