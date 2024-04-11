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
const ll INF = 1e18 + 1;
inline ll read()
{
	ll x = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return x;
}
int n, m;
struct node
{
	ll a, w, v, id;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.v == bb.v ? aa.w < bb.w : aa.v > bb.v;
	}
}p[maxn];
int pos[maxn], lev[maxn];
ll tmn[20][4 * maxn], tag[20][4 * maxn], t[20][4 * maxn][2];
inline void pushdown(int id, int x)
{
	tag[id][lc(x)] += tag[id][x];
	tag[id][rc(x)] += tag[id][x];
	tmn[id][lc(x)] += tag[id][x];
	tmn[id][rc(x)] += tag[id][x];
	tag[id][x] = 0;
}
void modify1(int id, int x, int l, int r, int pos, ll num)
{
	if(l == r)
	{
		if(p[l].a == 0) tmn[id][x] -= INF;
		else tmn[id][x] -= p[l].w;
		p[l].a += num;
		if(p[l].a == 0) tmn[id][x] += INF;
		else tmn[id][x] += p[l].w;
		return;
	}
	pushdown(id, x);
	int mid = (l + r) >> 1;
	if(pos <= mid) modify1(id, lc(x), l, mid, pos, num);
	else modify1(id, rc(x), mid + 1, r, pos, num);
	tmn[id][x] = min(tmn[id][lc(x)], tmn[id][rc(x)]);
}
void add(int id, int x, int l, int r, int a, int b, ll v)
{
	if(a > b) return;
	if(a <= l && r <= b)
	{
		tag[id][x] += v;
		tmn[id][x] += v;
		return;
	}
	pushdown(id, x);
	int mid = (l + r) >> 1;
	if(a <= mid) add(id, lc(x), l, mid, a, b, v);
	if(b > mid) add(id, rc(x), mid + 1, r, a, b, v);
	tmn[id][x] = min(tmn[id][lc(x)], tmn[id][rc(x)]);
} 
void modify2(int id, int x, int l, int r, int pos, ll a, ll b)
{
	if(l == r)
	{
		t[id][x][0] += a;
		t[id][x][1] += b;
		return;
	} 
	int mid = (l + r) >> 1;
	if(pos <= mid) modify2(id, lc(x), l, mid, pos, a, b);
	else modify2(id, rc(x), mid + 1, r, pos, a, b);
	t[id][x][0] = t[id][lc(x)][0] + t[id][rc(x)][0];
	t[id][x][1] = t[id][lc(x)][1] + t[id][rc(x)][1];
} 
int find1(int id, int x, int l, int r, int a, int b, ll c)
{
	if(a <= l && r <= b && tmn[id][x] > c) return n + 1;
	if(l == r) return l;
	pushdown(id, x);
	int mid = (l + r) >> 1, res = n + 1;
	if(a <= mid) res = find1(id, lc(x), l, mid, a, b, c);
	if(res <= n || b <= mid) return res;
	else return find1(id, rc(x), mid + 1, r, a, b, c);
}
int find2(int id, int x, int l, int r, int a, int b, ll &c)
{
	if(id < 0) return n + 1;
	if(a <= l && r <= b && t[id][x][0] <= c)
	{
		c -= t[id][x][0];
		return n + 1;
	}
	if(l == r) return l;
	int mid = (l + r) >> 1, res = n + 1;
	if(a <= mid) res = find2(id, lc(x), l, mid, a, b, c);
	if(res <= n || b <= mid) return res;
	else return find2(id, rc(x), mid + 1, r, a, b, c);
}
ll que(int id, int x, int l, int r, int a, int b, int tp)
{
	if(id < 0) return 0;
	if(a > b) return 0;
	if(a <= l && r <= b) return t[id][x][tp];
	int mid = (l + r) >> 1;
	ll res = 0;
	if(a <= mid) res += que(id, lc(x), l, mid, a, b, tp);
	if(b > mid) res += que(id, rc(x), mid + 1, r, a, b, tp);
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		p[i].a = read(), p[i].w = read(), p[i].v = read();
		p[i].id = i;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++) pos[p[i].id] = i;
	for (int i = 1; i <= n; i++)
	{
		for (ll j = p[i].w; j; j >>= 1) lev[i]++;
	}
	for (int i = 0; i < 20; i++) for (int j = 1; j <= 4 * n; j++) tmn[i][j] = INF;
	for (int i = 1; i <= n; i++)
	{
		int tmp = p[i].a;
		p[i].a = 0;
		modify1(lev[i], 1, 1, n, i, tmp);
		for (int j = lev[i]; j < 20; j++) modify2(j, 1, 1, n, i, p[i].w * p[i].a, p[i].v * p[i].a);
		for (int j = lev[i] + 1; j < 20; j++) add(j, 1, 1, n, i + 1, n, p[i].w * p[i].a);
	}
	while(m--)
	{
//		printf("check %lld\n", que(19, 1, 1, n, 1, n, 1));
		int tp = read();
		if(tp == 3)
		{
			ll c = read(), ans = 0;
			int now = 1;
			ll cc = c;
			while(now <= n)
			{
				ll las = c;
				int tmp = 0;
				for (ll j = c; j; j >>= 1) tmp++;
				int nxt1 = n + 1, nxt2 = n + 1;
				if(tmp < 20) nxt1 = find1(tmp, 1, 1, n, now, n, c + que(tmp - 1, 1, 1, n, 1, now - 1, 0));
				ll temp = c;
				nxt2 = find2(min(19, tmp - 1), 1, 1, n, now, n, temp);
				int nxtnow = min(nxt1, nxt2);
				c -= que(min(19, tmp - 1), 1, 1, n, now, nxtnow - 1, 0);
				ans += que(min(19, tmp - 1), 1, 1, n, now, nxtnow - 1, 1);
				int hoho = now;
				now = nxtnow;
				if(now == n + 1) break;
				if(!c) break;
				ll num = c / p[now].w;
				c -= num * p[now].w;
				ans += num * p[now].v;
//				printf("%d %d %d %lld %lld\n", nxt1, nxt2, now, ans, c);
//				if(n == 200000 && p[1].v == 100000 && p[1].w == 1 && c * 2 > las) printf("%d %d %d %d %lld %lld %lld \n", hoho, nxt1, nxt2, now, c, las, p[now].w);
				now++;
			}
//			if(n == 10 && ans == 351)
//			{
//				printf("%lld\n", cc);
//				for (int i = 1; i <= n; i++) printf("%lld ", p[i].a);
//				printf("\n");
//			}
			printf("%lld\n", ans);
		}
		else
		{
			ll num = (3 - tp * 2) * read(), id = pos[read()];
			modify1(lev[id], 1, 1, n, id, num);
			for (int j = lev[id]; j < 20; j++) modify2(j, 1, 1, n, id, p[id].w * num, p[id].v * num);
			for (int j = lev[id] + 1; j < 20; j++) add(j, 1, 1, n, id + 1, n, p[id].w * num);
		}
	}
	return 0;
}