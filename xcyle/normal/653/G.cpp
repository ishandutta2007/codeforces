/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 300005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int d[maxn][20];
int fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int val[maxn], sum[maxn];
int main()
{
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	scanf("%d", &n);
	for (int i = 1; i <= 300000; i++) d[i][0] = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = 2; j * j <= a[i]; j++)
		{
			if(a[i] % j != 0) continue;
			int cnt = 0;
			while(a[i] % j == 0)
			{
				cnt++;
				a[i] /= j;
			}
			d[j][cnt]++;
			d[j][0]--;
		}
		if(a[i] != 1)
		{
			d[a[i]][1]++;
			d[a[i]][0]--;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		val[i + 1] = (val[i + 2] + calc(n - 1, i + 1)) % mo;
//		printf("%d ", val[i + 1]);
	}
//	printf("\n");
	for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + val[i]) % mo; 
	int ans = 0;
	for (int i = 1; i <= 300000; i++)
	{
		if(d[i][0] == n) continue;
		int siz = 0;
		for (int j = 0; j < 20; j++)
		{
//			printf("%d ", d[i][j]);
			ans = (ans + mo -  (ll)j * (sum[siz + d[i][j]] - sum[siz] + mo) % mo) % mo;
			ans = (ans + (ll)j * (sum[n - siz] - sum[n - siz - d[i][j]] + mo) % mo) % mo;
			siz += d[i][j];
		}
//		printf("\n");
	}
	printf("%d\n", ans);
	return 0;
}