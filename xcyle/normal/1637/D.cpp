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
#define maxn 105
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], b[maxn];
int f[maxn][maxn * maxn];
void solve()
{
	n = read();
	int ans = 2 * maxn * maxn * maxn * maxn, tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		tmp += (n - 2) * a[i] * a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = read();
		tmp += (n - 2) * b[i] * b[i];
	}
	f[0][0] = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i] + b[i];
		for (int j = 0; j < maxn * maxn; j++)
		{
			f[i][j] = 0;
			if(j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
			if(j >= b[i]) f[i][j] |= f[i - 1][j - b[i]];
			if(i == n && f[i][j])
			{
				ans = min(ans, j * j + (sum - j) * (sum - j));
			}
		}
	}
	printf("%d\n", ans + tmp);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}