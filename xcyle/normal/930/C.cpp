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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, sum[maxn];
int t[maxn], f1[maxn], f2[maxn];
inline void add(int x, int d){for (; x <= m + 1; x += x & (-x)) t[x] = max(t[x], d);}
inline int que(int x){int res = 0; for (; x; x -= x & (-x)) res = max(res, t[x]); return res;}
int main()
{
	m = read(), n = read();
	for (int i = 1; i <= m; i++)
	{
		int l = read(), r = read();
		sum[l]++, sum[r + 1]--;
	}
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= n; i++)
	{
		f1[i] = que(sum[i] + 1) + 1;
		add(sum[i] + 1, f1[i]);
	}
	memset(t, 0, sizeof(t));
	int ans = 0;
	for (int i = n; i >= 1; i--)
	{
		f2[i] = que(sum[i] + 1) + 1;
		add(sum[i] + 1, f2[i]);
		ans = max(ans, f1[i] + f2[i] - 1);
	}
	printf("%d\n", ans);
	return 0;
}