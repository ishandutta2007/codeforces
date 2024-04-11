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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, cnt[200005], a[200005];
void solve()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++;
	for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	cnt[n + 1] = n * 3;
	int need = (n - k + 1) / 2 + k;
//	printf("!!!%d\n", need);
	int l = 1, r = n, pos = 1;
	for (int i = 1; i <= n; i++)
	{
		while(cnt[pos] - cnt[i - 1] < need) pos++;
		if(pos != n + 1)
		{
			if(pos - (i - 1) < r - l + 1)
			{
				l = i;
				r = pos;
			}
		}
	}
	printf("%d %d\n", l, r);
	int sum = 0;
	printf("1 ");
	for (int i = 1; i <= n; i++)
	{
		if(l <= a[i] && a[i] <= r) sum++;
		else sum--;
		if(sum > 0 && k > 1)
		{
			printf("%d\n%d ", i, i + 1);
			sum = 0;
			k--;
		}
	}
	printf("%d\n", n);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}