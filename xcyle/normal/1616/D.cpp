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
const ll INF = 1e15;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
ll a[maxn], x;
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	scanf("%lld", &x);
	for (int i = 1; i <= n; i++) a[i] -= x, a[i] += a[i - 1];
	ll mx1 = -INF, mx2 = -INF;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
//		printf("%d %d %d\n", i, ans, mx1);
		if(mx1 > a[i])
		{
			ans++;
			mx1 = -INF;
		}
		else mx1 = max(mx1, a[i - 1]);
	}
	printf("%d\n", n - ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}