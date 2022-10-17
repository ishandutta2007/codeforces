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
#define maxn 150005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, dep[maxn], siz[maxn], maxson[maxn];
int top[maxn], fa[maxn], dfn[maxn], out[maxn], tot;
int sum[maxn];
vector<int> G[maxn];
void dfs1(int x)
{
	siz[x] = 1;
	for (auto V: G[x]) if(V ^ fa[x])
	{
		fa[V] = x, dfs1(V);
		if(siz[V] > siz[maxson[x]]) maxson[x] = V;
		siz[x] += siz[V]; 
	}
}
void dfs2(int x, int anc)
{
	top[x] = anc, dfn[x] = ++tot;
	if(maxson[x]) dfs2(maxson[x], anc);
	for (auto V: G[x]) if(V ^ fa[x] && V ^ maxson[x]) dfs2(V, V);
	out[x] = tot;
}
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int t[maxn];
inline void add(int x, int v)
{
	for (; x <= n; x += x & (-x)) t[x] = (t[x] + v) % mo;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= x & (-x)) res = (res + t[x]) % mo;
	return res;
}
int main()
{
	n = read(), q = read();
	ru(i, 1, n - 1) {int x = read(), y = read(); G[x].push_back(y), G[y].push_back(x);}
	dfs1(1), dfs2(1, 1);
	int S = 0, invn = qpow(n, mo - 2);
	while(q--)
	{
		int op = read(), v = read();
		if(op == 1)
		{
			int d = read();
			S = (S + d) % mo, d = (mo - d) % mo;
			if(maxson[v])
			{
				int tmp = (ll)siz[maxson[v]] * d % mo;
				add(dfn[maxson[v]], tmp), add(out[maxson[v]] + 1, mo - tmp);
			}
			int tmp = (ll)(n - siz[v]) * d % mo;
			add(1, tmp), add(dfn[v], mo - tmp), add(out[v] + 1, tmp);
			sum[v] = (sum[v] + d) % mo;
 		}
		else
		{
			int ans = que(dfn[v]);
			for (; v; v = fa[v]) v = top[v], ans = (ans + (ll)sum[fa[v]] * siz[v] % mo) % mo;
			ans = ((ll)ans * invn % mo + S) % mo;
			printf("%d\n", ans);
		}
	}
	return 0;
}