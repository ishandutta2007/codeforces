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
#include <ctime>
#include <cstdlib>
#define maxn 100005
using namespace std;
const ll INF = 1e17;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[maxn];
ll tag1[maxn], tag2[maxn], val[maxn];
int rnk[maxn], siz[maxn], ch[maxn][2];
int tot;
int new_node(ll v)
{
	tot++;
	tag1[tot] = 0;
	tag2[tot] = 0;
	val[tot] = v;
	rnk[tot] = (ll)rand() * rand() % mo;
	siz[tot] = 1;
	ch[tot][0] = ch[tot][1] = 0;
	return tot;
}
int rt, x, y;
inline void work1(int x, ll v)
{
	tag1[x] += v;
	val[x] += v * (siz[ch[x][0]] + 1);
}
inline void work2(int x, ll v)
{
	tag2[x] += v;
	val[x] += v;
}
inline void pushdown(int x)
{
	work1(ch[x][0], tag1[x]);
	work1(ch[x][1], tag1[x]);
	work2(ch[x][1], tag1[x] * (siz[ch[x][0]] + 1));
	work2(ch[x][0], tag2[x]);
	work2(ch[x][1], tag2[x]);
	tag1[x] = tag2[x] = 0;
}
inline void pushup(int x)
{
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}
void split(int now, int rk, int &x, int &y)
{
	if(!now)
	{
		x = y = 0;
		return;
	}
	pushdown(now);
	if(rk <= siz[ch[now][0]])
	{
		y = now;
		split(ch[now][0], rk, x, ch[y][0]);
		pushup(y);
	}
	else
	{
		x = now;
		split(ch[now][1], rk - siz[ch[now][0]] - 1, ch[x][1], y);
		pushup(x);
	}
}
int merge(int x, int y)
{
	if(!x || !y) return x + y;
	if(rnk[x] < rnk[y])
	{
		pushdown(x);
		ch[x][1] = merge(ch[x][1], y);
		pushup(x);
		return x;
	}
	else
	{
		pushdown(y);
		ch[y][0] = merge(x, ch[y][0]);
		pushup(y);
		return y;
	}
}
void insert(int pos, ll val)//pospos+1val 
{
	split(rt, pos, x, y);
	rt = merge(merge(x, new_node(val)), y);
}
void modify(int pos, ll val1, ll val2)
{
//	printf("%d %d %d\n", pos, val1, val2);
	split(rt, pos, x, y);
	work1(y, val1), work2(y, val2);
	rt = merge(x, y); 
}
ll find(int rk)
{
//	printf("siz %d\n", siz[rt]);
	if(rk > siz[rt]) return -INF;
	int x = rt;
	while(1)
	{
		pushdown(x);
		if(rk <= siz[ch[x][0]]) x = ch[x][0];
		else if(siz[ch[x][0]] + 1 == rk) return val[x];
		else
		{
			rk -= siz[ch[x][0]] + 1;
			x = ch[x][1];
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	insert(0, 0);
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, mid;
		while(l < r)
		{
			mid = (l + r) >> 1;
			if(find(mid) + a[i] * mid > find(mid + 1)) r = mid;
			else l = mid +1;
		}
//		printf("%d %lld %lld\n", l, find(l), find(l + 1));
		ll tmp = find(l);
		insert(l - 1, tmp);
		modify(l, a[i], a[i] * (l - 1));
	}
	ll ans = 0;
	for (int i = 1; i <= n + 1; i++) ans = max(ans, find(i));
	printf("%lld\n", ans);
	return 0;
}