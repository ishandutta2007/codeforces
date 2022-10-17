/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 400005
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, l, r, ans; char s[maxn];
int sa[maxn], cnt[maxn], x[maxn], y[maxn], rk[maxn], h[maxn], L[maxn][25], R[maxn][25];
void init()
{
	int num = 30;
	ru(i, 1, n) cnt[x[i] = s[i] - 'a' + 1]++;
	ru(i, 1, num) cnt[i] += cnt[i - 1];
	ru(i, 1, n) sa[cnt[x[i]]--] = i;
	for (int k = 1; k <= n; k <<= 1)
	{
//	ru(i, 1, n) cerr<<sa[i]<<" ";
//	cerr<<endl;
		int tmp = 0;
		ru(i, n - k + 1, n) y[++tmp] = i;
		ru(i, 1, n) if(sa[i] > k) y[++tmp] = sa[i] - k;
		ru(i, 1, num) cnt[i] = 0;
		ru(i, 1, n) cnt[x[i]]++;
		ru(i, 1, num) cnt[i] += cnt[i - 1];
		rd(i, n, 1) sa[cnt[x[y[i]]]--] = y[i];
		num = 0; swap(x, y);
		ru(i, 1, n)
		{
			if(y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) x[sa[i]] = num;
			else x[sa[i]] = ++num;
		}
	}
	ru(i, 1, n) rk[sa[i]] = i;
	int now = 0;
	s[n + 1] = '{';
	ru(i, 1, n) if(rk[i] != 1)
	{
		if(now) now--;
		while(s[i + now] == s[sa[rk[i] - 1] + now]) now++;
		L[rk[i]][0] = R[rk[i] - 1][0] = h[rk[i]] = now;
	}
	ru(j, 1, 20) ru(i, 1, n)
	{
		if(i + (1 << j) - 1 <= n) R[i][j] = min(R[i][j - 1], R[i + (1 << (j - 1))][j - 1]);
		if(i - (1 << j) + 1 >= 1) L[i][j] = min(L[i][j - 1], L[i - (1 << (j - 1))][j - 1]);
	}
}
void find(int pos, int lim)
{
//	printf("! %d\n", lim);
	l = r = pos;
	rd(i, 20, 0) if(L[l][i] >= lim) l -= (1 << i);
	rd(i, 20, 0) if(R[r][i] >= lim) r += (1 << i);
	assert(1 <= l && l <= r && r <= n);
}
pii f[maxn], t1[maxn * 4]; int t2[maxn * 4];
void modify1(int x, int l, int r, int a, int b, pii val)
{
//	printf("%d %d %d\n", x, l, r);
	if(a <= l && r <= b) {t1[x] = min(t1[x], val); return;}
	if(a <= mid) modify1(lc(x), l, mid, a, b, val);
	if(b > mid) modify1(rc(x), mid + 1, r, a, b, val);
}
pii query1(int x, int l, int r, int pos)
{
//	printf("%d %d %d\n", x, l, r);
	if(l == r) return t1[x];
	if(pos <= mid) return min(t1[x], query1(lc(x), l, mid, pos));
	else return min(t1[x], query1(rc(x), mid + 1, r, pos));
}
void modify2(int x, int l, int r, int pos, int val)
{
//	printf("%d %d %d\n", x, l, r);
	t2[x] = min(t2[x], val);
	if (l == r) return;
	if(pos <= mid) modify2(lc(x), l, mid, pos, val);
	else modify2(rc(x), mid + 1, r, pos, val);
}
int query2(int x, int l, int r, int a, int b)
{
//	printf("%d %d %d\n", x, l, r);
	if(a <= l && r <= b) return t2[x];
	int res = 2 * n;
	if(a <= mid) res = min(res, query2(lc(x), l, mid, a, b));
	if(b > mid) res = min(res, query2(rc(x), mid + 1, r, a, b));
	return res;
}
int main()
{
	scanf("%d%s", &n, s + 1);
	init();
//	ru(i, 1, n) cerr<<sa[i]<<" ";
//	cerr<<endl;
//	return 0; 
	ru(i, 1, 4 * n) t2[i] = 2 * n;
	rd(i, n, 1)
	{
		f[i] = query1(1, 1, n, rk[i]); f[i].fi = -f[i].fi;
		if(f[i].fi)
		{
			find(rk[i], f[i].se); //printf("? %d %d %d %d\n", f[i].se, h[l], l, r);
			f[i].se = query2(1, 1, n, l, r) - i + f[i].se;
		}
		else f[i] = mp(1, 1);
		modify2(1, 1, n, rk[i], i);
		find(rk[i], f[i].se);
		modify1(1, 1, n, l, r, mp(-f[i].fi - 1, f[i].se));
		ans = max(ans, f[i].fi);
//		printf("%d %d\n", f[i].fi, f[i].se);
	}
	printf("%d\n", ans);
	return 0;
}