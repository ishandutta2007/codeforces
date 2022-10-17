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
#define maxn 250005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, anc[maxn][22], fa[maxn], dep[maxn];
vector<int> G[maxn], G2[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void init(int x, int fat)
{
	dep[x] = dep[fat] + 1, anc[x][0] = fat;
	ru(i, 1, 20) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (auto V: G[x]) if(V ^ fat) init(V, x);
}
inline int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	rd(i, 20, 0) if(dep[anc[y][i]] >= dep[x]) y = anc[y][i];
	if(x == y) return x;
	rd(i, 20, 0) if(anc[x][i] ^ anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
void dfs(int x, int fat)
{
	for (auto V: G2[x]) if(V ^ fat) dfs(V, x);
	if(!fat) return;
	int tmp = x, a; x = find(x);
	if(lca(x, fat) != x) a = x;
	else {a = fat; rd(i, 20, 0) if(dep[find(anc[a][i])] > dep[x]) a = anc[a][i];}
	printf("%d %d %d %d\n", a, anc[a][0], tmp, fat);
	fa[a] = find(anc[a][0]);
}
int main()
{
	n = read(); printf("%d\n", n - 1);
	ru(i, 1, n) fa[i] = i;
	ru(i, 1, n - 1) {int x = read(), y = read(); G[x].push_back(y), G[y].push_back(x);}
	ru(i, 1, n - 1) {int x = read(), y = read(); G2[x].push_back(y), G2[y].push_back(x);}
	init(1, 0), dfs(1, 0);
	return 0;
}