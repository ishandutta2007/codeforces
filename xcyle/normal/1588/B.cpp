/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
long long check(long long tot)
{
	ll l = 1, r = n, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if(mid * (mid - 1) / 2 >= tot) r = mid;
		else l = mid + 1;
	}
	if(l * (l - 1) / 2 == tot) return l;
	else return 0ll;
}
void out(int x, int y)
{
	printf("? %lld %lld\n", x, y);
	fflush(stdout);
}
void solve()
{
	scanf("%lld", &n);
	long long tot = 0;
	out(1, n);
	scanf("%lld", &tot);
	ll l = 1, r = n, mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		out(1, mid);
		long long x;
		scanf("%lld", &x);
		if(x == 0) l = mid + 1;
		else r = mid;
	}
	l--;
	out(l + 1, n);
	fflush(stdout);
	long long x;
	scanf("%lld", &x);
	x = tot - x;
	int y = check(tot - x * (x + 1) / 2);
	printf("! %lld %lld %lld\n", l, l + x + 1, l + x + y);
	fflush(stdout);
} 
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}