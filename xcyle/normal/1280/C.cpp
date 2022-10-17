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
#define maxn 200005
#define int long long
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, siz[maxn], maxson[maxn];
vector<pii> G[maxn];
ll g, b, sum = 0;
void dfs(int x, int fa, ll dep)
{
	siz[x] = 1, maxson[x] = 0; sum += dep;
	for (auto t: G[x]) if(t.fi != fa)
	{
		int V = t.fi, W = t.se;
		dfs(V, x, dep + W);
		if(siz[V] & 1) g += W; 
		siz[x] += siz[V];
		maxson[x] = max(maxson[x], siz[V]);
	}
	maxson[x] = max(maxson[x], 2 * n - siz[x]);
}
void dfs2(int x, int fa)
{
	if(maxson[x] * 2 <= 2 * n) b = max(b, sum);
	for (auto t: G[x]) if(t.fi != fa)
	{
		int V = t.fi, W = t.se;
		sum += (ll)W * (2 * n - 2 * siz[V]);
		dfs2(V, x);
		sum -= (ll)W * (2 * n - 2 * siz[V]);
	}
} 
void solve()
{
	n = read();
	ru(i, 1, 2 * n) G[i].clear();
	ru(i, 1, 2 * n - 1)
	{
		int x = read(), y = read(), z = read();
		G[x].push_back(mp(y, z));
		G[y].push_back(mp(x, z));
	}
	g = b = sum = 0;
	dfs(1, 0, 0);
	dfs2(1, 0);
	printf("%lld %lld\n", g, b);
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}