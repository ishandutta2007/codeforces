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
#define maxn 4000005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, f[maxn];
int fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo; 
}
inline int calcinv(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)ifac[x] * fac[y] % mo * fac[x - y] % mo; 
}
void init()
{
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	ru(i, 2, maxn - 1)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
}
int main()
{
	n = read(), m = read();
	init();
	int tmp = 0;
	ru(i, 0, n + m - 1)
	{
		tmp = (tmp + (ll)calc(n + m - i - 1, m - 1) * (i + 1) % mo * calcinv(n + m, m) % mo) % mo;
	}
	int sum = 0;
	rd(i, n - 1, 0)
	{
		f[i] = (tmp + (ll)sum * calcinv(n + m - i, m) % mo) % mo;
		f[i] = (ll)f[i] * (n - i + m) % mo * inv[n - i] % mo;
		sum = (sum + (ll)f[i] * calc(n + m - i - 1, m - 1) % mo) % mo;
	}
	printf("%d\n", f[0]);
	return 0;
}