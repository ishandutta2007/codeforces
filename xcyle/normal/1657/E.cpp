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
#define maxn 255
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, f[maxn][maxn], c[maxn][maxn];
inline int pw(int x, int step)
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
	c[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo; 
	}
	f[k + 1][0] = 1;
	for (int i = k; i >= 1; i--)
	{
		for (int las = 0; las < n; las++)
		{
			int tot = 0;
			for (int now = 0; now + las < n; now++)
			{
				f[i][las + now] = (f[i][las + now] + (ll)pw(i, tot) * f[i + 1][las] % mo * c[now + las][now] % mo) % mo;
				tot += las + now;
			}
		}
	}
	printf("%d\n", f[1][n - 1]);
	return 0;
}