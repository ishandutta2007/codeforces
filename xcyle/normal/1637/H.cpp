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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], id[maxn];
ll val[maxn];
int t[maxn];
inline void add(int x){for (; x <= n; x += x & (-x)) t[x]++;}
inline int que(int x){int res = 0; for (; x; x -= x & (-x)) res += t[x]; return res;}
inline bool cmp(int x, int y){return val[x] < val[y];}
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), t[i] = 0, val[i] = a[i] - 1, id[i] = i;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		add(a[i]);
		val[i] -= (i - que(a[i]));
		ans += (i - que(a[i]));
	}
	for (int i = 1; i <= n; i++) t[i] = 0;
	for (int i = n; i >= 1; i--)
	{
		val[i] += que(a[i]);
		add(a[i]);
	}
	sort(id + 1, id + n + 1, cmp);
	printf("%lld ", ans);
	for (int i = 1; i <= n; i++)
	{
		ans += val[id[i]];	
		printf("%lld ", ans - (ll)i * (i - 1) / 2);
	}
	printf("\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}