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
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int m, fac[maxn]; 
ll num[maxn];
int c[maxn];
inline int calc(ll x, ll y)
{
	ll a = x + y, b = y - x + 1;
	if(a % 2 == 0) a /= 2;
	else b /= 2;
	a %= mo, b %= mo;
	return (ll)a * b % mo;
}
int main()
{
	m = read();
	for (int i = 1; i <= m; i++) c[i] = read();
	ll n = 0;
	for (int i = 1; i <= m; i++) n += c[i];
	fac[0] = 1;
	for (int i = 1; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % mo;
	sort(c + 1, c + m + 1);
	for (int i = 1; i <= m; i++) num[c[i] - 1]++;
	for (int i = maxn - 3; i >= 0; i--) num[i] += num[i + 2];
	int ans1 = 0, ans2 = 1;
	for (int i = 1; i < maxn; i++) ans2 = (ll)ans2 * fac[num[i]] % mo * fac[num[i]] % mo;
	ans2 = (ll)ans2 * fac[num[0]] % mo;
	for (int i = maxn - 2; i >= 1; i--)
	{
		num[i] += num[i + 1];
		ans1 = (ans1 + (ll)i * (calc(n - num[i] + 1, n - num[i + 1]) + mo - calc(num[i + 1] + 1, num[i])) % mo) % mo;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}