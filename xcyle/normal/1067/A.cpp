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
#define maxn 100005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int f[maxn][205][2], sum[maxn][205][2];
int main()
{
	scanf("%d", &n);
	a[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	f[0][0][1] = 1;
	for (int i = 0; i <= 200; i++) sum[0][i][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if(a[i] != -1)
		{
			f[i][a[i]][0] = (sum[i - 1][a[i] - 1][0] + sum[i - 1][a[i] - 1][1]) % mo;
			f[i][a[i]][1] = (f[i - 1][a[i]][0] + f[i - 1][a[i]][1]) % mo;
			f[i][a[i]][1] = (f[i][a[i]][1] + (sum[i - 1][200][1] - sum[i - 1][a[i]][1] + mo) % mo) % mo;
		}
		else
		{
			for (int j = 1; j <= 200; j++)
			{
				f[i][j][0] = (sum[i - 1][j - 1][0] + sum[i - 1][j - 1][1]) % mo;
				f[i][j][1] = (f[i - 1][j][0] + f[i - 1][j][1]) % mo;
				f[i][j][1] = (f[i][j][1] + (sum[i - 1][200][1] - sum[i - 1][j][1] + mo) % mo) % mo;
			}	
		}
		for (int j = 1; j <= 200; j++)
		{
//			if(j <= 3) printf("%d %d %d\n", j, f[i][j][0], f[i][j][1]);
			sum[i][j][0] = (sum[i][j - 1][0] + f[i][j][0]) % mo;
			sum[i][j][1] = (sum[i][j - 1][1] + f[i][j][1]) % mo;
		}
	}
	printf("%d\n", sum[n][200][1]);
	return 0;
}