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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
vector<ll> c[maxn];
void solve()
{
	n = read(), m = read();
	ll mx = -1;
	ru(i, 1, n)
	{
		c[i].clear();
		c[i].push_back(0);
		ll sum = 0, sum2 = 0;
		ru(j, 1, m)
		{
			ll x = read();
			c[i].push_back(x);
			sum += x, sum2 += sum;
		}
		mx = max(mx, sum2);
	}
	ru(i, 1, n)
	{
		ll sum = 0, sum2 = 0;
		ru(j, 1, m)
		{
			ll x = c[i][j];
			sum += x, sum2 += sum;
		}
		if(sum2 < mx)
		{
			printf("%lld %lld\n", i, mx - sum2);
			return;
		}
	}
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}