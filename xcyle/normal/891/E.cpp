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
#define maxn 5005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], f[maxn][maxn];
inline int ksm(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int main()
{
	n = read(), k = read();
	f[0][0] = 1;
	ru(i, 1, n)
	{
		a[i] = read(), f[i][0] = (ll)f[i - 1][0] * a[i] % mo;
		ru(j, 1, i) f[i][j] = ((ll)f[i - 1][j] * a[i] % mo + mo - f[i - 1][j - 1]) % mo;
	}
	int tmp = 0, bas = 1;
	ru(i, 0, n)
	{
		tmp = (tmp + (ll)f[n][i] * bas % mo) % mo;
		bas = (ll)bas * ksm(n, mo - 2) % mo * (k - i) % mo; 
	}
	printf("%d\n", (mo + f[n][0] - tmp) % mo);
	return 0;
}