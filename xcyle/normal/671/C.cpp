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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], vis[maxn];
vector<int> pos[maxn];
ll sum[maxn * 4];
int tag[maxn * 4];
inline void pushdown(int x, int l, int r)
{
	if(!tag[x]) return;
	tag[lc(x)] = tag[rc(x)] = tag[x];
	sum[lc(x)] = (ll)tag[x] * (mid - l + 1), sum[rc(x)] = (ll)tag[x] * (r - mid);
	tag[x] = 0;
}
int query(int x, int l, int r, int pos)
{
	if(l == r) return sum[x];
	pushdown(x, l, r);
	if(pos <= mid) return query(lc(x), l, mid, pos);
	else return query(rc(x), mid + 1, r, pos);
}
ll que(int x, int l, int r, int a, int b, int v)
{
	if(a <= l && r <= b) 
	{
		ll tmp = sum[x];
		tag[x] = v; sum[x] = (ll)(r - l + 1) * v;
		return tmp;
	}
	pushdown(x, l, r);
	ll res = 0;
	if(a <= mid) res += que(lc(x), l, mid, a, b, v);
	if(b > mid) res += que(rc(x), mid + 1, r, a, b, v);
	sum[x] = sum[lc(x)] + sum[rc(x)];
	return res;
}
void build(int x, int l, int r)
{
	if(l == r) {sum[x] = l; return;}
	build(lc(x), l, mid), build(rc(x), mid + 1, r);
	sum[x] = sum[lc(x)] + sum[rc(x)];
}
inline ll work(int l, int r)
{
	if(l > r || query(1, 1, n, l) > r) return 0;
	int L = l, R = r, M;
	while(L < R)
	{
		M = (L + R + 1) >> 1;
		if(query(1, 1, n, M) > r) R = M - 1;
		else L = M;
	}
	int pos = L;
	ll tmp = (ll)(pos - l + 1) * (r + 1) - que(1, 1, n, l, pos, r + 1);
	return tmp;
}
int main()
{
	n = read();
	ru(i, 1, n) vis[a[i] = read()] = i;
	ru(i, 1, maxn - 1) ru(j, 1, (maxn - 1) / i) if(vis[i * j]) pos[i].push_back(vis[i * j]);
	build(1, 1, n);
	ll ans = 0;
	rd(i, maxn - 1, 1)
	{
		if(pos[i].size() < 2) continue;
		sort(pos[i].begin(), pos[i].end());
//		for (auto x : pos[i]) printf("%d ", x); printf("\n");
		ll tot = work(1, pos[i][pos[i].size() - 2] - 1); //printf("%lld\n", tot);
		tot += work(pos[i][0] + 1, pos[i][pos[i].size() - 1] - 1); //printf("%lld\n", tot);
		//ru(i, 1, n) printf("%d ", query(1, 1, n, i)); printf("\n");
		//printf("!%d\n", pos[i][1] + 1);
		tot += work(pos[i][1] + 1, n);// printf("%lld\n", tot);
		ans += tot * i;
		//if(tot) printf("%d %lld\n", i, tot);
	}
	printf("%lld\n", ans);
	return 0;
}