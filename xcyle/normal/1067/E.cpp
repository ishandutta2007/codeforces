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
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, f[maxn], g[maxn], ans[maxn];
vector<int> G[maxn];
void dfs(int x, int fa)
{
	f[x] = g[x] = 1; int tmp = 1;
	for (auto V: G[x]) if(V ^ fa)
	{
		dfs(V, x);
		f[x] = (ll)f[x] * (g[V] + f[V]) % mo, g[x] = (ll)g[x] * g[V] % mo * 2 % mo;
		ans[x] = (ll)ans[x] * g[V] % mo * 2 % mo;
		tmp = (ll)tmp * 2 % mo;
		ans[x] = (ans[x] + (ll)tmp * ans[V] % mo) % mo;
		tmp = (ll)tmp * g[V] % mo;
	}
	f[x] = (g[x] + mo - f[x]) % mo;
	ans[x] = (ans[x] + f[x]) % mo;
}
int main()
{
	n = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", 2 * ans[1] % mo);
	return 0;
}