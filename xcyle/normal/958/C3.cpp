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
#define maxn 500005
#define maxk 105
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, p, a[maxn];
int f[maxk][maxn];
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] = (a[i] + a[i - 1]) % p;
	}
	for (int i = 1; i <= n; i++) f[1][i] = 0;
	for (int i = 2; i <= k; i++)
	{
		int mn = n, mn2 = n, pos = p, pos2 = p;
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = min(mn + (pos > a[j] ? 1 : 0), mn2 + (pos > a[j] ? 1 : 0));
			if(f[i - 1][j] < mn)
			{
				mn2 = mn, pos2 = pos;
				mn = f[i - 1][j];
				pos = a[j];
			}
			else if(f[i - 1][j] == mn) pos = min(pos, a[j]);
			else if(f[i - 1][j] == mn2) pos2 = min(pos2, a[j]);
		}
	}
	printf("%lld\n", (ll)f[k][n] * p + a[n]);
	return 0;
}