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
int T, n, a[maxn];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int res = 0;
	a[n + 1] = 2e9;
	for (int i = 1; i < n; i++)
	{
		int tmp = upper_bound(a + 1, a + n + 2, a[i]) - a;
		int now = a[tmp] - a[i];
		if(tmp == n + 1)
		{
			res = max(res, n + 1 - i);
			continue;
		}
		tmp = tmp - i + 1;
		while(1)
		{
			int loc = lower_bound(a + 1, a + n + 2, a[i] + 2 * now) - a;
			if(loc > n) break;
			now = a[loc] - a[i];
			tmp++;
		}
		res = max(res, tmp);
	}
	printf("%d\n", n - res);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}