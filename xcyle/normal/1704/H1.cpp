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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 5005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, mo, fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int f[maxn][maxn], pw[maxn][maxn];
int main()
{
	n = read(), mo = read();
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	ru(i, 2, maxn - 1)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	ru(i, 0, n)
	{
		pw[i][0] = 1;
		ru(j, 1, n) pw[i][j] = (ll)pw[i][j - 1] * i % mo;
	}
	f[0][0] = 1;
	ru(i, 1, n) ru(j, 2 * i, n) f[i][j] = (ll)calc(j - i - 1, i - 1) * fac[j] % mo * ifac[i] % mo * pw[n - 1][i] % mo;
	int ans = 0;
	ru(i, 0, n)
	{
		ru(j, 2 * i, n)
		{
			ans = (ans + (ll)f[i][j] * calc(n, j) % mo * pw[j - i][n - j] % mo) % mo;
		}
	}
	printf("%d\n", ans);
	return 0;
}