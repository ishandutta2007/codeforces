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
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, fa[maxn], v[maxn], siz[maxn], maxson[maxn], dep[maxn], buc[1 << 22], ans[maxn], id[maxn], tot, L[maxn], R[maxn];
vector<int> G[maxn];
void init(int x)
{
	siz[x] = 1, id[++tot] = x, L[x] = tot;
	for (auto V: G[x])
	{
		init(V), siz[x] += siz[V];
		if(siz[V] > siz[maxson[x]]) maxson[x] = V;
	}
	R[x] = tot;
}
inline int check(int x)
{
	int res = buc[x];
	ru(i, 0, 21) res = max(res, buc[x ^ (1 << i)]);
	return res;
}
void dfs(int x)
{
	for (auto V: G[x]) if(V ^ maxson[x])
	{
		dfs(V), ans[x] = max(ans[x], ans[V]);
		ru(i, L[V], R[V]) buc[v[id[i]]] = -INF;
	}
	if(maxson[x]) dfs(maxson[x]), ans[x] = max(ans[x], ans[maxson[x]]);
	ans[x] = max(ans[x], check(v[x]) - dep[x]), buc[v[x]] = max(buc[v[x]], dep[x]);
	for (auto V: G[x]) if(V ^ maxson[x])
	{
		ru(i, L[V], R[V]) ans[x] = max(ans[x], check(v[id[i]]) + dep[id[i]] - 2 * dep[x]);
		ru(i, L[V], R[V]) buc[v[id[i]]] = max(buc[v[id[i]]], dep[id[i]]);
	}
}
int main()
{
	n = read();
	ru(i, 0, (1 << 22) - 1) buc[i] = -INF;
	ru(i, 2, n) 
	{
		char s[2]; scanf("%d%s", &fa[i], s);
		G[fa[i]].push_back(i), dep[i] = dep[fa[i]] + 1;
		v[i] = v[fa[i]] ^ (1 << (s[0] - 'a'));
	}
	init(1), dfs(1);
	ru(i, 1, n) printf("%d ", ans[i]);
	return 0;
}