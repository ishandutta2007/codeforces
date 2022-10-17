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
#define db double
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
int T, n, m, k;
int fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	if(m == 0)
	{
		printf("0\n");
		return;
	}
	m--;
	int ans = calc(n, m);
	int tmp = inv[2];
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + (ll)(i + 3) * tmp % mo * calc(n - i, m - i) % mo) % mo;
		tmp = (ll)tmp * 2 % mo;
	}
	for (int i = 1; i <= n; i++) ans = (ll)ans * inv[2] % mo;
	printf("%d\n", (ll)ans * 2 % mo * k % mo);
}
int main()
{
	inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}