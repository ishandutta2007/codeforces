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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, val[maxn], siz[maxn], f[maxn], g[maxn];
vector<int> G[maxn], col[maxn], pos[maxn];
void dfs(int x, int fa)
{
	for (int i = 0; i < G[x].size(); i++) if(G[x][i] == fa) val[x] = col[x][i];
	siz[x] = 1; int bef = pos[val[x]].size();
	for (auto V: G[x]) if(V ^ fa) dfs(V, x), siz[x] += siz[V];
	if(x == 1) return;
	f[x] += siz[x];
	while(pos[val[x]].size() > bef) f[x] -= siz[pos[val[x]].back()], pos[val[x]].pop_back();
	pos[val[x]].push_back(x);
}
ll ans = 0;
vector<int> las[maxn];
void dfs2(int x, int fa)
{
	int y = las[val[x]].back();
	ans += (ll)f[x] * (y == 1 ? g[val[x]] : f[y]);
	las[val[x]].push_back(x);
	for (auto V: G[x]) if(V ^ fa) dfs2(V, x);
	las[val[x]].pop_back();
} 
int main()
{
	n = read();
	ru(i, 1, n - 1) 
	{
		int x = read(), y = read(), c = read();
		G[x].push_back(y), col[x].push_back(c);
		G[y].push_back(x), col[y].push_back(c);
	}
	dfs(1, 0);
	ru(i, 1, n)
	{
		g[i] = n;
		for (auto x: pos[i]) g[i] -= siz[x];
	}
	ru(i, 0, n) las[i].push_back(1);
	dfs2(1, 0);
	printf("%lld\n", ans);
	return 0;
}