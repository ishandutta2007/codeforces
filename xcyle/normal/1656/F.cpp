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
#define maxn 200005
using namespace std;
const ll INF = 5e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[maxn];
inline ll calc(ll x, ll y, ll z)
{
	return x * y + z * (x + y);
}
inline ll check(int t)
{
	ll res = calc(a[1], a[n], t);
	for (int i = 2; i < n; i++)
	{
		if(a[i] + t < 0) res += calc(a[i], a[n], t);
		else res += calc(a[i], a[1], t);
	}
	return res;
}
ll work()
{
	int l = 0, r = 1e6, mid;
	if(check(r + 1) > check(r)) return INF;
	while(l < r)
	{
		mid = (l + r) >> 1;
		if(check(mid) < check(mid + 1)) l = mid + 1;
		else r = mid;
	}
	return check(l);
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	ll ans = work();
	for (int i = 1; i <= n; i++) a[i] = -a[i];
	sort(a + 1, a + n + 1);
	ans = max(ans, work());
	if(ans == INF) printf("INF\n");
	else printf("%lld\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}