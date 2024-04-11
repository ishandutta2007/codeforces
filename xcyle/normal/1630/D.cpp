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
#define maxn 1000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int gcd(int x, int y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y); 
}
int sum[maxn], mn[maxn];
inline int Abs(int x)
{
	return x > 0 ? x : -x;
}
void solve()
{
	int n = read(), m = read();
	for (int i = 0; i <= n; i++) sum[i] = 0, mn[i] = INF;
	for (int i = 1; i <= n; i++) a[i] = read();
	int d = read();
	for (int i = 1; i < m; i++) d = gcd(d, read());
	for (int i = 1; i <= n; i++)
	{
		if(a[i] < 0) sum[i % d] ^= 1;
		mn[i % d] = min(mn[i % d], Abs(a[i]));
	}
	ll ans1 = 0, ans2 = 0;
	for (int i = 0; i < d; i++)
	{
		ans1 += sum[i] * mn[i];
		ans2 += (1 - sum[i]) * mn[i];
	}
	ans1 = min(ans1, ans2);
	ans1 = -2 * ans1;
	for (int i = 1; i <= n; i++)
	{
		ans1 += Abs(a[i]);
	}
	printf("%lld\n", ans1);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}