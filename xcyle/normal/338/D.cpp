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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
ll n, m, a[10005], k;
inline ll gcd(ll x, ll y)
{
	return y == 0 ? x : gcd(y, x % y);
}
void exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
}
inline ll mul(ll x, ll y, ll mo)
{
	x = (x % mo + mo) % mo;
	y = (y % mo + mo) % mo;
	ll res = 0;
	for (; y; y >>= 1)
	{
		if(y & 1ll) res = (res + x) % mo;
		x = (x + x) % mo;
	}
	return res;
}
int main()
{
	scanf("%lld%lld%d", &n, &m, &k);
	for (int i = k - 1; i >= 0; i--) scanf("%lld", &a[i]);
	ll N = 1, M = 0;
	for (int i = 0; i < k; i++)
	{
		ll nxtN = N / gcd(N, a[i]);
		if(nxtN > n / a[i])
		{
			printf("NO\n");
			return 0;
		}
		nxtN *= a[i];
		ll d = gcd(N, a[i]);
		if((M - i) % d != 0)
		{
			printf("NO\n");
			return 0;
		}
		ll x, y;
		exgcd(N, a[i], x, y);
		M = (M + mul(N, mul(x, (i - M) / d, a[i]), nxtN)) % nxtN;
		N = nxtN;
//		printf("%lld %lld %lld %lld %lld\n", N, a[i], x, y, M);
	}
	if(M < k) M += ((k - M + N - 1) / N) * N;
	if(M > m || M < k)
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 0; i < k; i++)
	{
		if(gcd(M - i, N) != a[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}