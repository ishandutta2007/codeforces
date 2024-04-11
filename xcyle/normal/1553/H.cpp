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
#define maxn (1 << 19)
#define INF (1 << (k + 1))
#define t (1 << (k - i - 1))
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, ans[20][maxn], mn[20][maxn], mx[20][maxn]; 
int main()
{
	n = read(), k = read();
	for (int i = 0; i < (1 << k); i++) for (int j = 0; j < k; j++) ans[j][i] = mn[k][i] = INF, mx[k][i] = -INF;
	for (int i = 1; i <= n; i++) {int x = read(); mn[k][x] = mx[k][x] = 0;}
	for (int i = k - 1; i >= 0; i--) for (int j = 0; j < (1 << k); j++)
	{
		mn[i][j] = min(mn[i + 1][j], mn[i + 1][j ^ t] + t);
		mx[i][j] = max(mx[i + 1][j], mx[i + 1][j ^ t] + t);
		ans[i][j & (2 * t - 1)] = min(ans[i][j & (2 * t - 1)], mn[i + 1][j ^ t] + t - mx[i + 1][j]);
	}
	for (int i = 0; i < (1 << k); i++)
	{
		int res = INF;
		for (int j = 0; j < k; j++) res = min(res, ans[j][i & ((1 << (k - j)) - 1)]); 
		printf("%d ", res);
	}
	return 0;
}