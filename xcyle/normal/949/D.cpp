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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, d, B;
int a[maxn], b[maxn];
int sumb[maxn];
int work()
{
	for (int i = 1; i <= n; i++) sumb[i] = sumb[i - 1] + b[i];
//	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
//	printf("\n");
//	for (int i = 1; i <= n; i++) printf("%d ", sumb[i]);
//	printf("\n");
	int cnt = 0;
	int now = 0, need = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		need += B;
		now = min(now + 1 + d, n);
		if(sumb[now] < need) cnt++, need -= B;
	}
	return cnt;
}
int main()
{
	scanf("%d%d%d", &n, &d, &B);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 0, r = B * n, mid, ans = n;
		mid = (n/2)*B;
//		mid = 2;
		int L, R;
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			if(tot + a[i] >= mid)
			{
				b[i] = mid - tot;
				break;
			}
			b[i] = a[i];
		}
		L = work();
		tot = 0;
		for (int i = n; i >= 1; i--)
		{
			if(tot + a[i] >= n * B - mid)
			{
				b[n - i + 1] = n * B - mid - tot;
				break;
			}
			b[n - i + 1] = a[i];
		}
		R = work();
//		printf("%d %d\n", L, R);
		ans = min(ans, max(L, R));
		if(L > R) l = mid + 1;
		else r = mid - 1;
	printf("%d\n", ans);
	return 0;
}