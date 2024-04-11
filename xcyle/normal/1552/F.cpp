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
#define maxn 400005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, f[maxn], t[maxn], x[maxn], y[maxn], s[maxn];
int tmp[maxn], loc[maxn];
inline void add(int x, int val){for (; x <= 2 * n; x += x & (-x)) t[x] = (t[x] + val) % mo;}
inline int que(int x){int res = 0; for (; x; x -= x & (-x)) res = (res + t[x]) % mo; return res;}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) tmp[2 * i - 1] = x[i] = read(), tmp[2 * i] = y[i] = read(), s[i] = read();
	int ans = x[n] + 1;
	sort(tmp + 1, tmp + 2 * n + 1);
	for (int i = n; i >= 1; i--)
	{
		int loc = lower_bound(tmp + 1, tmp + 2 * n + 1, x[i]) - tmp;
		f[i] = (que(loc) + s[i]) % mo;
		loc = lower_bound(tmp + 1, tmp + 2 * n + 1, y[i]) - tmp;
		add(loc, f[i]);
		ans = (ans + (ll)(x[i] - y[i]) * f[i] % mo) % mo;
	}
	printf("%d\n", ans);
	return 0;
}