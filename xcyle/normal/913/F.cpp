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
#define maxn 2005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline int Pow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int n, a, b, p[maxn][maxn], g[maxn], f[maxn];
int p0[maxn], p1[maxn], inv[maxn];
int val[maxn];
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	inv[1] = 1;
	for (int i = 2; i <= 100; i++) inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
	for (int i = 1; i <= n; i++) val[i] = (ll)i * (i - 1) % mo * inv[2] % mo;
	p0[0] = p1[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p0[i] = (ll)p0[i - 1] * a % mo * inv[b] % mo;
		p1[i] = (ll)p1[i - 1] * (b - a) % mo * inv[b] % mo;
	}
	p[1][0] = p[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			p[i][j] = ((ll)p[i - 1][j - 1] * p0[i - j] % mo + (ll)p[i - 1][j] * p1[j] % mo) % mo;
//			printf("%d %d %d\n", i, j, p[i][j]);
		}
	}
	g[0] = g[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		g[i] = 1;
		for (int j = 1; j < i; j++)
		{
			g[i] = (g[i] + mo - (ll)g[j] * p[i][j] % mo) % mo;
		}
//		printf("%d\n", g[i]);
	}
	f[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[i] = (ll)g[i] * val[i] % mo;
		for (int j = 1; j < i; j++)
		{
			int tmp = ((f[j] + f[i - j]) % mo + (val[i] - val[i - j] + mo) % mo) % mo;
			f[i] = (f[i] + (ll)p[i][j] * g[j] % mo * tmp % mo) % mo;
		}
		f[i] = (ll)f[i] * Pow(1 + mo - g[i], mo - 2) % mo;
	}
	printf("%d\n", f[n]);
	return 0;
}