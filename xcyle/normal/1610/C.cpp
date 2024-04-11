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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[maxn], b[maxn];
int check(int t)
{
	int pos = 1;
	for (int i = 1; i <= t; i++)
	{
		while((b[pos] < i - 1 || a[pos] < t - i) && pos <= n) pos++;
		if(pos == n + 1) return 0;
		pos++;
	}
	return 1;
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	int l = 0, r = n, mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}