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
#define maxn 600005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
ll a[maxn];
ll sum0[maxn], sum1[maxn];
int sta[maxn], R[maxn], tot;
long long tmp[maxn];
int t[maxn * 20], ch[maxn * 20][2];
void modify(int x, int l, int r, int aim)
{
	t[x]++;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(!ch[x][0])
	{
		ch[x][0] = ++tot;
		t[tot] = 0;
	}
	if(!ch[x][1])
	{
		ch[x][1] = ++tot;
		t[tot] = 0;
	}
	if(aim <= mid) modify(ch[x][0], l, mid, aim);
	else modify(ch[x][1], mid + 1, r, aim);
}
int que(int x, int l, int r, int a, int b)
{
	if(a < 1 || b > n || a > b) return 0;
	if(a <= l && r <= b) return t[x];
	int mid = (l + r) >> 1;
	if(!ch[x][0])
	{
		ch[x][0] = ++tot;
		t[tot] = 0;
	}
	if(!ch[x][1])
	{
		ch[x][1] = ++tot;
		t[tot] = 0;
	}
	int res = 0;
	if(a <= mid) res += que(ch[x][0], l, mid, a, b);
	if(b > mid) res += que(ch[x][1], mid + 1, r, a, b);
	return res;
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		sum0[i] = sum1[i - 1] - a[i];
		sum1[i] = sum0[i - 1] + a[i];
		R[i] = n;
		tmp[2 * i - 1] = sum1[i];
		tmp[2 * i] = sum0[i];
	}
	R[0] = n;
	tmp[2 * n + 1] = 0;
	sort(tmp + 1, tmp + 2 * n + 2);
	int len = unique(tmp + 1, tmp + 2 * n + 2) - tmp - 1;
	sum1[n + 1] = -9e16;
	int top = 0;
	sta[0] = n + 1;
	long long ans = 0;
	for (int i = n; i >= 0; i--)
	{
		if(i & 1)
		{
			int l = 0, r = top, mid;
			while(l < r)
			{
				mid = (l + r + 1) >> 1;
				if(sum1[sta[mid]] < sum1[i]) l = mid;
				else r = mid - 1;
			}
			R[i] = min(R[i], sta[l] - 1);
		}
		else
		{
			int l = 0, r = top, mid;
			while(l < r)
			{
				mid = (l + r + 1) >> 1;
				if(sum1[sta[mid]] < sum0[i]) l = mid;
				else r = mid - 1;
			}
			R[i] = min(R[i], sta[l] - 1);
		}
		if(i & 1)
		{
			while(top && sum1[sta[top]] >= sum1[i]) top--;
			sta[++top] = i;
		}
	}
	top = 0;
	sta[top] = n + 1;
	for (int i = n; i >= 0; i--)
	{
		if(i % 2 == 0)
		{
			int l = 0, r = top, mid;
			while(l < r)
			{
				mid = (l + r + 1) >> 1;
				if(sum1[sta[mid]] < sum1[i]) l = mid;
				else r = mid - 1;
			}
			R[i] = min(R[i], sta[l] - 1);
		}
		else
		{
			int l = 0, r = top, mid;
			while(l < r)
			{
				mid = (l + r + 1) >> 1;
				if(sum1[sta[mid]] < sum0[i]) l = mid;
				else r = mid - 1;
			}
			R[i] = min(R[i], sta[l] - 1);
		}
		if(i % 2 == 0)
		{
			while(top && sum1[sta[top]] >= sum1[i]) top--;
			sta[++top] = i;
		}
	}
//	for (int i = 0; i <= n; i++) printf("%d ", R[i]);
//	printf("\n");
	for (int i = 1; i <= tot; i++) t[i] = 0;
	for (int i = 1; i <= tot; i++) ch[i][0] = ch[i][1] = 0;
	tot = 2 * n + 2;
	for (int i = n; i >= 0; i--)
	{
		if(i & 1)
		{
			int loc = lower_bound(tmp + 1, tmp + len + 1, sum1[i]) - tmp;
			ans += que(loc, 1, n, i + 1, R[i]);
			modify(loc, 1, n, i);
		}
		else
		{
			int loc = lower_bound(tmp + 1, tmp + len + 1, sum0[i]) - tmp;
			ans += que(loc, 1, n, i + 1, R[i]);
		}
//			printf("%d %d\n", i, ans);
	}
	for (int i = 1; i <= tot; i++) t[i] = 0;
	for (int i = 1; i <= tot; i++) ch[i][0] = ch[i][1] = 0;
	tot = 2 * n + 2;
	for (int i = n; i >= 0; i--)
	{
		if(i % 2 == 0)
		{
			int loc = lower_bound(tmp + 1, tmp + len + 1, sum1[i]) - tmp;
			ans += que(loc, 1, n, i + 1, R[i]);
			modify(loc, 1, n, i);
		}
		else
		{
			int loc = lower_bound(tmp + 1, tmp + len + 1, sum0[i]) - tmp;
			ans += que(loc, 1, n, i + 1, R[i]);
		}
//			printf("%d %d\n", i, ans);
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}