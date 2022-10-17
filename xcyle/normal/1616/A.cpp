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
#define maxn 105
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[maxn];
int cnt[maxn];
void solve()
{
	scanf("%d", &n);
	for (int i = 0; i <= 100; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x > 0 ? x : -x]++;
	}
	int ans = min(1, cnt[0]);
	for (int i = 1; i <= 100; i++) ans += min(cnt[i], 2);
	printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}