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
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, x, a[1000005];
void solve()
{
	n = read(), x = read();
	int mn = 1e9 + 1, mx = 0, ans = 0;
	ru(i, 1, n) 
	{
		a[i] = read();
		mn = min(mn, a[i]), mx = max(mx, a[i]);
		if(mx - mn > 2 * x)
		{
			ans++;
			mn = mx = a[i];
		}
	}
	printf("%lld\n", ans - (mn > mx));
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}