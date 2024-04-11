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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
ll n;
int q;
int main()
{
	scanf("%lld%d", &n, &q);
	for (int i = 1; i <= q; i++)
	{
		ll x;
		scanf("%lld", &x);
		if(x % 2 == 1)
		{
			printf("%lld\n", (x + 1) / 2);
			continue;
		}
		ll las = x;
		x = n + x / 2;
		while(x % 2 != 1 && x != las)
		{
			ll tmp = x;
			x += (x - las) / 2;
			las = tmp;
//			printf("%lld\n", x);
		}
		if(x == 2 * n - 2) printf("%lld\n", n);
		else printf("%lld\n", (x + 1) / 2);
	}
	return 0;
}