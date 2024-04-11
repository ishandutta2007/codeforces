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
int n, m, q;
int a[maxn], b[maxn], las[maxn], fa[maxn][22], ans[maxn];
int pos[maxn];
int main()
{
	n = read(), m = read(), q = read();
	ru(i, 1, n) a[i] = read(), las[a[i]] = a[i - 1]; las[a[1]] = a[n];
	ru(i, 1, m)
	{
		ans[i] = ans[i - 1], b[i] = read();
		pos[b[i]] = i;
		fa[i][0] = pos[las[b[i]]];//, printf("%d ", fa[i][0]);
		ru(j, 1, 20) fa[i][j] = fa[fa[i][j - 1]][j - 1];
		int now = i;
		rd(j, 20, 0) if(((n - 1) >> j) & 1) now = fa[now][j];
		ans[i] = max(ans[i], now);
	}
	ru(i, 1, q)
	{
		int l = read(), r = read();
		printf("%d", l <= ans[r]);
	}
	return 0;
}