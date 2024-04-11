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
using namespace std;
const int INF = 1e9 + 1;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, xl[maxn], xr[maxn], yl[maxn], yr[maxn];
inline void check(int x, int y)
{
	int cnt = 0;
	ru(i, 1, n)
	{
		cnt += (xl[i] <= x && x <= xr[i] && yl[i] <= y && y <= yr[i]);
	}
	if(cnt >= n - 1)
	{
		printf("%d %d\n", x, y);
		exit(0);
	}
}
int main()
{
	n = read();
	int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
	ru(i, 1, n)
	{
		xl[i] = read(), yl[i] = read(), xr[i] = read(), yr[i] = read();
		mnx = min(mnx, xr[i]);
		mxx = max(mxx, xl[i]);
		mny = min(mny, yr[i]);
		mxy = max(mxy, yl[i]);
	}
	check(mnx, mny), check(mxx, mxy), check(mnx, mxy), check(mxx, mny);
	return 0;
}