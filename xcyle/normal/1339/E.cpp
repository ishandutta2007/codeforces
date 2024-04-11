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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
ll N;
int a[12] = {0, 0, 0, 1, 2, 3, 2, 3, 1, 3, 1, 2};
void solve()
{
	ll n; scanf("%lld", &n);
	int now = 0;
	while((1ll << (now + 2)) <= n) now += 2;
	n -= (1ll << now);
	ll ans = n % 3 + 1;
	int tp = n % 3;
	n /= 3;
	for (; now > 0; now -= 2)
	{
		n %= (1ll << now);
		ans = ans * 4 + a[(n / (1ll << (now - 2))) * 3 + tp];
	}
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}