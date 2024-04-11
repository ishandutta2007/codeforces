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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, b[maxn][maxn], r[maxn * maxn], c[maxn * maxn], ans[maxn * maxn];
int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[i][j] = read();
			r[b[i][j]] = i, c[b[i][j]] = j;
		}
	}
	int a[4] = {-3 * n, -3 * n, -3 * n, -3 * n};
	for (int i = n * n; i >= 1; i--)
	{
		int mx = max(max(a[0] - r[i] - c[i], a[1] + r[i] - c[i]), max(a[2] - r[i] + c[i], a[3] + r[i] + c[i]));
		if(mx <= k)
		{
			ans[i] = 1;
			a[0] = max(a[0], r[i] + c[i]);
			a[1] = max(a[1], -r[i] + c[i]);
			a[2] = max(a[2], r[i] - c[i]);
			a[3] = max(a[3], -r[i] - c[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(ans[b[i][j]]) printf("M");
			else printf("G");
		}
		printf("\n");
	}
	return 0;
}