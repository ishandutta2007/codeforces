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
int n, f[maxn], g[maxn], sum[maxn];
vector<int> G[maxn];
void dfs(int x, int fa)
{
	g[x] = x;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x), f[x] ^= (f[V] + 1), g[x] = min(g[x], g[V]);
	for (auto V: G[x]) if(V ^ fa) sum[g[x]] ^= (f[V] + 1), sum[g[V]] ^= (f[V] + 1) ^ 1;
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
	ru(i, 1, n) sum[i] ^= sum[i - 1];
	ru(i, 1, n) printf("%d", sum[i] ? 1 : 2);
	return 0;
}