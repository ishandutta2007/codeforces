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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, ans[maxn];
vector<int> G[maxn];
int fa[maxn][22], dep[maxn];
void dfs(int x)
{
	for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (auto V: G[x])
	{
		if(V == fa[x][0]) continue;
		fa[V][0] = x;
		dep[V] = dep[x] + 1;
		dfs(V); 
	}
}
inline int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
	{
		if(dep[fa[y][i]] >= dep[x]) y = fa[y][i];
	} 
	if(x == y) return x;
	for (int i = 20; i >= 0; i--)
	{
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
inline int path(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)]; 
}
inline bool cmp(int x, int y)
{
	return dep[x] > dep[y];
}
int id[maxn];
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	int x = id[1], y = id[1];
	for (int i = 1; i <= n + 1; i++) ans[i] = n;
	ans[n] = dep[id[1]];
	for (int i = 1; i < n; i++)
	{
		if(path(id[i], x) > path(x, y)) swap(id[i], y);
		if(path(id[i], y) > path(x, y)) swap(id[i], x);
		ans[max(0, dep[id[i + 1]] - (path(x, y) + 1) / 2)] = dep[id[i + 1]];
	}
	for (int i = n; i >= 1; i--) ans[i] = min(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}