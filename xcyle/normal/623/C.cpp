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
#define maxn 100005
using namespace std;
const ll INF = 4e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, x[maxn], y[maxn];
int xl[maxn], xr[maxn], yl[maxn], yr[maxn];
int tmp[maxn];
ll ans = INF;
struct node
{
	int l, r, pos;
	inline bool operator < (const node &a) const
	{
		return pos < a.pos;
	}
}pre[maxn], suf[maxn];
int Lp[maxn], Rp[maxn], Ls[maxn], Rs[maxn];
int Lpos[maxn], Rpos[maxn];
int check(int l)
{
	ru(i, 1, n)
	{
		xl[i] = abs(x[i]), xr[i] = min(l, x[i] + l);
		yl[i] = abs(y[i]), yr[i] = min(l, y[i] + l); 
//		printf("%d %d %d %d\n", xl[i], xr[i], yl[i], yr[i]);
		pre[i] = {yl[i], yr[i], xr[i]};
		suf[i] = {yl[i], yr[i], xl[i]};
	}
	sort(pre + 1, pre + n + 1), sort(suf + 1, suf + n + 1);
	Lp[0] = Ls[n + 1] = 0, Rp[0] = Rs[n + 1] = l;
	ru(i, 1, n)
	{
		Lp[i] = max(pre[i].l, Lp[i - 1]);
		Rp[i] = min(pre[i].r, Rp[i - 1]);
	}
	rd(i, n, 1)
	{
		Ls[i] = max(suf[i].l, Ls[i + 1]);
		Rs[i] = min(suf[i].r, Rs[i + 1]);
	}
	for (int i = 1, j = 0; i <= n; i++)
	{
		while(j < n && pre[j + 1].pos < tmp[i]) j++;
		Lpos[i] = j;
	}
	for (int i = n, j = n + 1; i >= 1; i--)
	{
		while(j > 1 && suf[j - 1].pos > tmp[i]) j--;
		Rpos[i] = j;
	}
	ru(i, 1, n) if(tmp[i] >= 0)
	{
		int LL = max(Lp[Lpos[i]], Ls[Rpos[i]]), RR = min(Rp[Lpos[i]], Rs[Rpos[i]]);
//		printf("%d %d %d %d %lld\n", Lpos, Rpos, LL, RR, t);
		if(LL > RR) continue;
		if((ll)LL * LL + (ll)tmp[i] * tmp[i] <= (ll)l * l) return 1; 
	}
	return 0;
}
ll check2(int l)
{
	ru(i, 1, n)
	{
		xl[i] = abs(x[i]), xr[i] = min(l, x[i] + l);
		yl[i] = abs(y[i]), yr[i] = min(l, y[i] + l); 
//		printf("%d %d %d %d\n", xl[i], xr[i], yl[i], yr[i]);
		pre[i] = {yl[i], yr[i], xr[i]};
		suf[i] = {yl[i], yr[i], xl[i]};
	}
	sort(pre + 1, pre + n + 1), sort(suf + 1, suf + n + 1);
	Lp[0] = Ls[n + 1] = 0, Rp[0] = Rs[n + 1] = l;
	ru(i, 1, n)
	{
		Lp[i] = max(pre[i].l, Lp[i - 1]);
		Rp[i] = min(pre[i].r, Rp[i - 1]);
	}
	rd(i, n, 1)
	{
		Ls[i] = max(suf[i].l, Ls[i + 1]);
		Rs[i] = min(suf[i].r, Rs[i + 1]);
	}
	for (int i = 1, j = 0; i <= n; i++)
	{
		while(j < n && pre[j + 1].pos < tmp[i]) j++;
		Lpos[i] = j;
	}
	for (int i = n, j = n + 1; i >= 1; i--)
	{
		while(j > 1 && suf[j - 1].pos > tmp[i]) j--;
		Rpos[i] = j;
	}
	ll res = INF;
	ru(i, 1, n) if(tmp[i] >= 0)
	{
		int LL = max(Lp[Lpos[i]], Ls[Rpos[i]]), RR = min(Rp[Lpos[i]], Rs[Rpos[i]]);
//		printf("%d %d %d %d %lld\n", Lpos, Rpos, LL, RR, t);
		if(LL > RR) continue;
		res = min(res, (ll)LL * LL + (ll)tmp[i] * tmp[i]);
	}
	return res;
}
void work()
{
	ru(i, 1, n) tmp[i] = x[i]; sort(tmp + 1, tmp + n + 1);
	int l = 0, r = 2e8;
	while(l < r)
	{
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	ans = min(ans, (ll)l * l);
	ans = min(ans, check2(l - 1));
}
int main()
{
	n = read();
	int mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
	ru(i, 1, n) x[i] = read(), y[i] = read(), mnx = min(mnx, x[i]), mxx = max(mxx, x[i]), mny = min(mny, y[i]), mxy = max(mxy, y[i]);
	ans = min(ans, (ll)(mxx - mnx) * (mxx - mnx));
	ans = min(ans, (ll)(mxy - mny) * (mxy - mny));
	work();
	ru(i, 1, n) x[i] = -x[i];
	work();
	ru(i, 1, n) y[i] = -y[i];
	work();
	ru(i, 1, n) x[i] = -x[i];
	work();
	printf("%lld\n", ans); 
	return 0;
}