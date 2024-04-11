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
int n, m, q;
ll a[maxn], b[maxn];
ll t[maxn * 4], tag[maxn * 4];
void build(int x, int l, int r)
{
	if(l == r)
	{
		t[x] = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(x), l, mid);
	build(rc(x), mid + 1, r);
	t[x] = t[lc(x)] + t[rc(x)];
}
inline void pushdown(int x, int l, int r)
{
	if(!tag[x]) return;
	tag[lc(x)] += tag[x], tag[rc(x)] += tag[x];
	int mid = (l + r) >> 1;
	t[lc(x)] += tag[x] * (mid - l + 1), t[rc(x)] += tag[x] * (r - mid);
	tag[x] = 0;
} 
void modify(int x, int l, int r, int a, int b, ll d)
{
	if(a <= l && r <= b)
	{
		t[x] += d * (r - l + 1);
		tag[x] += d;
		return;
	}
	pushdown(x, l, r);
	int mid = (l + r) >> 1;
	if(a <= mid) modify(lc(x), l, mid, a, b, d);
	if(b > mid) modify(rc(x), mid + 1, r, a, b, d);
	t[x] = t[lc(x)] + t[rc(x)];
}
ll que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return t[x];
	pushdown(x, l, r);
	ll res = 0;
	int mid = (l + r) >> 1;
	if(a <= mid) res += que(lc(x), l, mid, a, b);
	if(b > mid) res += que(rc(x), mid + 1, r, a, b);
	return res;
}
ll t2[maxn];
inline void add(int x, ll d)
{
	for (; x <= m; x += (x & (-x))) t2[x] += d;
}
int find(ll x)
{
	int pos = 0;
	for (int i = 20; i >= 0; i--)
	{
		if(pos + (1 << i) > m || t2[pos + (1 << i)] > x) continue;
		pos += (1 << i);
		x -= t2[pos];
	}
//	printf("!!! %d\n", pos);
	return pos;
} 
ll calc()
{
	ll res = (a[1] + que(1, 1, m, 1, 1)) * (n + m - 1);
	for (int i = 2; i <= n; i++) res += a[i] * (n - i + 1);
//	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
//	printf("\n%lld\n", res);
	for (int i = 2; i <= n; i++)
	{
		int pos = find(a[i]);
		res += a[i] * (m - pos);
		res += que(1, 1, m, 2, pos);
	}
	return res;
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
	for (int i = m; i >= 1; i--) b[i] -= b[i - 1];
	build(1, 1, m);
	add(2, b[2]);
	for (int i = 3; i <= m; i++) add(i, b[i] - b[i - 1]); 
	ll ans = 0;
	for (int i = 2; i <= m; i++) ans += b[i] * (m - i + 1);
	for (int i = 1; i <= q; i++)
	{
		int tp, cnt;
		ll d;
		scanf("%d%d%lld", &tp, &cnt, &d);
		if(tp == 1)
		{
			for (int j = n - cnt + 1; j <= n; j++) a[j] += d;
		}
		else
		{
			modify(1, 1, m, m - cnt + 1, m, d);
			cnt = min(cnt, m - 1);
			add(m - cnt + 1, d);
			ans += (ll)cnt * (cnt + 1) / 2 * d;
		}
		printf("%lld\n", calc() + ans);
	}
	return 0;
}