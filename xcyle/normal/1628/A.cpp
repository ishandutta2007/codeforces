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
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[maxn];
int r[maxn], ans[maxn];
int t[maxn * 4], vis[maxn];
void add(int x, int l, int r, int aim, int d)
{
	if(l == r)
	{
		t[x] = d;
		return;
	}
	int mid = (l + r) >> 1;
	if(aim <= mid) add(lc(x), l, mid, aim, d);
	else add(rc(x), mid + 1, r, aim, d);
	t[x] = max(t[lc(x)], t[rc(x)]);
}
int que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b)
	{
		return t[x];
	}
	int res = 0, mid = (l + r) >> 1;
	if(a <= mid)
	{
		res = max(res, que(lc(x), l, mid, a, b));
	}
	if(b > mid) res = max(res, que(rc(x), mid + 1, r, a, b));
	return res;
}
vector<int> res;
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n * 4; i++) t[i] = n + 1;
	for (int i = 0; i <= n; i++) vis[i] = 0;
	int now = 0;
	for (int i = n; i >= 1; i--)
	{
		add(1, 0, n, a[i], i);
		vis[a[i]] = 1;
		while(now <= n && vis[now]) now++;
		if(now == 0) r[i] = i;
		else r[i] = que(1, 0, n, 0, now - 1);
		ans[i] = now;
//		printf("%d %d %d\n", i, ans[i], r[i]);
	}
	now = 1;
	res.clear();
	while(now <= n)
	{
		res.push_back(ans[now]);
		now = r[now] + 1;
	}
	printf("%d\n", res.size());
	for (auto x: res) printf("%d ", x);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}