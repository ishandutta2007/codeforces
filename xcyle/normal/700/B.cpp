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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, rt, vis[maxn], sum[maxn];
vector<int> G[maxn];
void dfs(int x, int fa)
{
	int mx = 0;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x), sum[x] += sum[V], mx = max(mx, sum[V]);
	mx = max(mx, 2 * k - sum[x]);
	if(mx <= k) rt = x;
}
ll ans = 0;
void dfs2(int x, int fa, int dep)
{
	ans += (ll)dep * vis[x];
	for (auto V: G[x]) if(V ^ fa) dfs2(V, x, dep + 1);
}
int main()
{
	n = read(), k = read();
	ru(i, 1, 2 * k) {int x = read(); vis[x]++, sum[x]++;}
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	dfs2(rt, 0, 0);
	printf("%lld\n", ans);
	return 0;
}