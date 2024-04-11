/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 2000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[maxn], b[maxn], m;
struct node
{
	int d, tp, pos;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.d == bb.d ? aa.tp > bb.tp : aa.d < bb.d;
	}
}c[maxn];
int tt[maxn], tep[maxn], len;
int t[maxn * 4], tag[maxn * 4];
inline void add(int x)
{
	for (; x <= len; x += (x & (-x))) tt[x]++;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= (x & (-x))) res += tt[x];
	return res;
}
void pushdown(int x)
{
	tag[lc(x)] += tag[x];
	tag[rc(x)] += tag[x];
	t[lc(x)] += tag[x];
	t[rc(x)] += tag[x];
	tag[x] = 0;
}
void addd(int x, int l, int r, int a, int b, int data)
{
	if(a <= l && r <= b)
	{
		tag[x] += data;
		t[x] += data;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) addd(lc(x), l, mid, a, b, data);
	if(b > mid) addd(rc(x), mid + 1, r, a, b, data);
	t[x] = min(t[lc(x)], t[rc(x)]);
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) tep[i] = a[i];
	sort(tep + 1, tep + n + 1);
	len = unique(tep + 1, tep + n + 1) - tep - 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++) tt[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int loc = lower_bound(tep + 1, tep + len + 1, a[i]) - tep;
		add(loc);
		ans += i - que(loc);
	}
//	printf("!#@$!@%lld\n", ans);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= n; i++) c[i] = {a[i], 0, i};
	for (int i = 1; i <= m; i++) c[i + n] = {b[i], 1, i};
	sort(c + 1, c + n + m + 1);
	for (int i = 1; i <= 4 * (n + 1); i++) t[i] = 0;
	for (int i = 1; i <= 4 * (n + 1); i++) tag[i] = 0;
	for (int i = 1; i <= n; i++) addd(1, 1, n + 1, i + 1, n + 1, 1);
	int now = 1;
	for (int i = 1; i <= n + m; i++)
	{
		while(c[now].d == c[i].d && now <= n + m)
		{
			if(c[now].tp == 0) 
			{
				addd(1, 1, n + 1, c[now].pos + 1, n + 1, -1);
//				printf("%d %d -1\n", c[now].pos + 1, n + 1);
			}
			now++;
		}
		if(c[i].tp == 1)
		{
			 ans += t[1];
//			 printf("! %d %d\n", c[i].d, t[1]);
		}
		else addd(1, 1, n + 1, 1, c[i].pos, 1);//, printf("1 %d 1\n", c[i].pos);
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}