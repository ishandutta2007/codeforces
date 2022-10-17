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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
inline ll gcd(ll x, ll y)
{
	return !y ? x : gcd(y, x % y);
}
ll calc(int x)
{
	ll res = 0;
	ru(i, 0, n) res = max(res, (ll)n * k / gcd((ll)n * k, (ll)i * k + x));
	return res;
}
ll calc2(int x)
{
	ll res = (ll)n * k;
	ru(i, 0, n) res = min(res, (ll)n * k / gcd((ll)n * k, (ll)i * k + x));
	return res;
}
int main()
{
	n = read(), k = read();
	int a = read(), b = read();
	printf("%lld ", min(min(calc2(a + b), calc2(a + k - b)), calc2(k - a + k - b))); 
	printf("%lld ", max(max(calc(a + b), calc(a + k - b)), calc(k - a + k - b))); 
	return 0;
}