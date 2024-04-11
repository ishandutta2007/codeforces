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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, siz[maxn], ans[maxn], fa[maxn];
vector<int> G[maxn];
void dfs(int x)
{
	siz[x] = 1;
	if(!G[x].size()) {ans[x] = x; return;}
	int maxson = G[x][0];
	for (auto V: G[x])
	{
		dfs(V), siz[x] += siz[V];
		if(siz[V] > siz[maxson]) maxson = V;
	}
	ans[x] = ans[maxson];
	while(siz[x] - siz[ans[x]] > (siz[ans[x]] - 1)) ans[x] = fa[ans[x]];
}
int main()
{
	n = read(), q = read();
	ru(i, 2, n) G[fa[i] = read()].push_back(i);
	dfs(1);
	while(q--) printf("%d\n", ans[read()]);
	return 0;
}