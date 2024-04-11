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
#define N 40000005//log or 4log?
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, ans[maxn], tot;
int L[maxn], R[maxn];
struct node
{
	int l, r, id;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.r - aa.l > bb.r - bb.l;
	}
}p[maxn];
int t[N], ch[N][2];
void modify(int x, int l, int r, int a, int d)
{
	if(l == r)
	{
		t[x] = min(t[x], d);
		return;
	}
	if(!ch[x][0]) ch[x][0] = ++tot, t[ch[x][0]] = m + 1;
	if(!ch[x][1]) ch[x][1] = ++tot, t[ch[x][1]] = m + 1;
	int mid = (l + r) >> 1;
	if(a <= mid) modify(ch[x][0], l, mid, a, d);
	else modify(ch[x][1], mid + 1, r, a, d);
	t[x] = min(t[ch[x][0]], t[ch[x][1]]);
}
void add(int x, int l, int r, int a, int b, int d)
{
	modify(x, 1, n, b, d);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(a <= mid) add(lc(x), l, mid, a, b, d);
	else add(rc(x), mid + 1, r, a, b, d); 
}
int query(int x, int l, int r, int a, int b)
{
	if(!x) return m + 1;
	if(a <= l && r <= b) return t[x];
	int mid = (l + r) >> 1, res = m + 1;
	if(a <= mid) res = min(res, query(ch[x][0], l, mid, a, b));
	if(b > mid) res = min(res, query(ch[x][1], mid + 1, r, a, b));
	return res;
}
int que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return query(x, 1, n, a, b);
	int mid = (l + r) >> 1, res = m + 1;
	if(a <= mid) res = min(res, que(lc(x), l, mid, a, b));
	if(b > mid) res = min(res, que(rc(x), mid + 1, r, a, b));
	return res;
}
int calc(int l, int r)
{
	if(l > r) return 0;
	int pos = que(1, 1, n, l, r);
	if(pos == m + 1) return 0;
	return R[pos] - L[pos] + 1 + calc(l, L[pos] - 1) + calc(R[pos] + 1, r);
}
int main()
{
	scanf("%d%d", &n, &m);
	tot = 4 * n;
	for (int i = 1; i <= n * 4; i++) t[i] = m + 1;
	for (int i = 1; i <= m; i++)
	{
		p[i].l = L[i] = read();
		p[i].r = R[i] = read();
		p[i].id = i;
	}
	sort(p + 1, p + m + 1);
	int now = 1;
	for (int i = n; i >= 1; i--)
	{
		while(now <= m && p[now].r - p[now].l + 1 == i)
		{
			add(1, 1, n, p[now].r, p[now].l, p[now].id);
			now++;
		}
		ans[i] = calc(1, n);
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}