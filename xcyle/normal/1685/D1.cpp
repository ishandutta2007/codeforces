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
#define maxn 405
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, p[maxn], fa[maxn], pf[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void solve()
{
	n = read();
	ru(i, 1, n) pf[p[i] = read()] = i, fa[i] = i;
	ru(i, 1, n) fa[find(i)] = find(p[i]);
	ru(i, 1, n)
	{
		int j = i;
		while(j < n && find(j + 1) != find(i)) p[pf[j]] = j + 1, j++, fa[find(j)] = find(i);
		p[pf[j]] = i, i = j;
	}
	ru(i, 1, n) pf[p[i]] = i;
	for (int i = 1, now = 1; i <= n; i++, now = pf[now]) printf("%d ", now); printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}