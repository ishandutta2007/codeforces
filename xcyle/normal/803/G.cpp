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
#define maxn 10000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn];
int ch[maxn][2], tot;
int t[maxn], tag[maxn];
int st[100005][25], LOG[maxn];
inline int val(int l, int r)
{
	return min(st[l][LOG[r - l + 1]], st[r - (1 << LOG[r - l + 1]) + 1][LOG[r - l + 1]]);
}
inline int val2(ll l, ll r)
{
	if((r - 1) / n - (l - 1) / n > 1) return val(1, n);
	else if((r - 1) / n - (l - 1) / n == 1) return min(val((l - 1) % n + 1, n), val(1, (r - 1) % n + 1));
	else return val((l - 1) % n + 1, (r - 1) % n + 1); 
}
inline void pushdown(int x, ll l, ll r)
{
	ll mid = (l + r) / 2;
	if(!ch[x][0])
	{
		ch[x][0] = ++tot;
		t[tot] = val2(l, mid);
	}
	if(!ch[x][1])
	{
		ch[x][1] = ++tot;
		t[tot] = val2(mid + 1, r);
	}
	if(!tag[x]) return;
	tag[ch[x][0]] = tag[x];
	tag[ch[x][1]] = tag[x];
	t[ch[x][0]] = tag[x];
	t[ch[x][1]] = tag[x];
	tag[x] = 0;
}
void add(int x, ll l, ll r, ll a, ll b, int d)
{
	if(a <= l && r <= b)
	{
		tag[x] = d;
		t[x] = d;
		return;
	}
	ll mid = (l + r) / 2;
	pushdown(x, l, r);
	if(a <= mid) add(ch[x][0], l, mid, a, b, d);
	if(b > mid) add(ch[x][1], mid + 1, r, a, b, d);
	t[x] = min(t[ch[x][0]], t[ch[x][1]]);
} 
int que(int x, ll l, ll r, ll a, ll b)
{
	if(a <= l && r <= b) return t[x];
	ll mid = (l + r) / 2;
	pushdown(x, l, r);
	int res = INF;
	if(a <= mid) res = min(res, que(ch[x][0], l, mid, a, b));
	if(b > mid) res = min(res, que(ch[x][1], mid + 1, r, a, b));
	return res;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) a[i] = read();
	LOG[1] = 0; 
	for (int i = 1; i < 20; i++) for (int j = (1 << i); j < (1 << (i + 1)); j++) LOG[j] = i;
	for (int i = n; i >= 1; i--)
	{
		st[i][0] = a[i];
		for (int j = 1; j <= 20; j++)
		{
			if(i + (1 << j) - 1 > n) continue;
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); 
		} 
	}
	t[1] = val(1, n);
	tot = 1;
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int tp = read();
		long long l = read(), r = read();
		if(tp == 1) add(1, 1, (long long)n * k, l, r, read());
		else printf("%d\n", que(1, 1, (long long)n * k, l, r));
	}
	return 0;
}