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
using namespace std;
const ll INF = 6e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n; ll lim[2][2][2], p, q, r, s;
inline int check2(ll Lp, ll Rp, ll Lq, ll Rq, ll Lr, ll Rr, ll Ls, ll Rs)
{
	if(Lp > Rp || Lq > Rq || Lr > Rr || Ls > Rs) return 0;
	return Lp + Ls - Rq - Rr <= 0 && 0 <= Rp + Rs - Lq - Lr;
}
int check(ll dis)
{
	ll Lp = lim[1][1][1] - dis, Rp = dis - lim[0][0][0];
	ll Lq = lim[1][0][1] - dis, Rq = dis - lim[0][1][0];
	ll Lr = lim[1][1][0] - dis, Rr = dis - lim[0][0][1];
	ll Ls = lim[1][0][0] - dis, Rs = dis - lim[0][1][1];
	if(Lp > Rp || Lq > Rq || Lr > Rr || Ls > Rs) return 0;
	ll tLp = (Lp - 1) / 2, tRp = (Rp - 1) / 2;
	ll tLq = (Lq - 1) / 2, tRq = (Rq - 1) / 2;
	ll tLr = (Lr - 1) / 2, tRr = (Rr - 1) / 2;
	ll tLs = (Ls - 1) / 2, tRs = (Rs - 1) / 2;
	if(tLp * 2 + 1 < Lp) tLp++; if(tRp * 2 + 1 > Rp) tRp--;
	if(tLq * 2 + 1 < Lq) tLq++; if(tRq * 2 + 1 > Rq) tRq--;
	if(tLr * 2 + 1 < Lr) tLr++; if(tRr * 2 + 1 > Rr) tRr--;
	if(tLs * 2 + 1 < Ls) tLs++; if(tRs * 2 + 1 > Rs) tRs--;
	if(check2(tLp, tRp, tLq, tRq, tLr, tRr, tLs, tRs)) return 1;
	tLp = (Lp) / 2, tRp = (Rp) / 2;
	tLq = (Lq) / 2, tRq = (Rq) / 2;
	tLr = (Lr) / 2, tRr = (Rr) / 2;
	tLs = (Ls) / 2, tRs = (Rs) / 2;
	if(tLp * 2 < Lp) tLp++; if(tRp * 2 > Rp) tRp--;
	if(tLq * 2 < Lq) tLq++; if(tRq * 2 > Rq) tRq--;
	if(tLr * 2 < Lr) tLr++; if(tRr * 2 > Rr) tRr--;
	if(tLs * 2 < Ls) tLs++; if(tRs * 2 > Rs) tRs--;
	if(check2(tLp, tRp, tLq, tRq, tLr, tRr, tLs, tRs)) return 1;
	return 0;
}
void work3(ll L1, ll R1, ll L2, ll R2, ll &X1, ll &X2, ll sum)
{
	assert(L1 + L2 <= sum && sum <= R1 + R2);
	X1 = max(L1, sum - R2), X2 = sum - X1;
	assert(L1 <= R1);// && L2 <= x2 && x2 <= R2);
}
inline int work2(ll Lp, ll Rp, ll Lq, ll Rq, ll Lr, ll Rr, ll Ls, ll Rs)
{
	if(Lp > Rp || Lq > Rq || Lr > Rr || Ls > Rs) return 0;
	if(!(Lp + Ls - Rq - Rr <= 0 && 0 <= Rp + Rs - Lq - Lr)) return 0;
	ll sum = max(Lp + Ls, Lq + Lr);
	work3(Lp, Rp, Ls, Rs, p, s, sum);
	work3(Lq, Rq, Lr, Rr, q, r, sum);
	return 1;
}
void work(ll dis)
{
	ll Lp = lim[1][1][1] - dis, Rp = dis - lim[0][0][0];
	ll Lq = lim[1][0][1] - dis, Rq = dis - lim[0][1][0];
	ll Lr = lim[1][1][0] - dis, Rr = dis - lim[0][0][1];
	ll Ls = lim[1][0][0] - dis, Rs = dis - lim[0][1][1];
	ll tLp = (Lp - 1) / 2, tRp = (Rp - 1) / 2;
	ll tLq = (Lq - 1) / 2, tRq = (Rq - 1) / 2;
	ll tLr = (Lr - 1) / 2, tRr = (Rr - 1) / 2;
	ll tLs = (Ls - 1) / 2, tRs = (Rs - 1) / 2;
	if(tLp * 2 + 1 < Lp) tLp++; if(tRp * 2 + 1 > Rp) tRp--;
	if(tLq * 2 + 1 < Lq) tLq++; if(tRq * 2 + 1 > Rq) tRq--;
	if(tLr * 2 + 1 < Lr) tLr++; if(tRr * 2 + 1 > Rr) tRr--;
	if(tLs * 2 + 1 < Ls) tLs++; if(tRs * 2 + 1 > Rs) tRs--;
	if(work2(tLp, tRp, tLq, tRq, tLr, tRr, tLs, tRs))
	{
		p = p * 2 + 1, q = q * 2 + 1, r = r * 2 + 1, s = s * 2 + 1;
//		printf("%lld %lld %lld\n", Lp, p, Rp);
//		printf("%lld %lld %lld\n", Lq, q, Rq);
//		printf("%lld %lld %lld\n", Lr, r, Rr);
//		printf("%lld %lld %lld\n", Ls, s, Rs);
		return;
	}
	tLp = (Lp) / 2, tRp = (Rp) / 2;
	tLq = (Lq) / 2, tRq = (Rq) / 2;
	tLr = (Lr) / 2, tRr = (Rr) / 2;
	tLs = (Ls) / 2, tRs = (Rs) / 2;
	if(tLp * 2 < Lp) tLp++; if(tRp * 2 > Rp) tRp--;
	if(tLq * 2 < Lq) tLq++; if(tRq * 2 > Rq) tRq--;
	if(tLr * 2 < Lr) tLr++; if(tRr * 2 > Rr) tRr--;
	if(tLs * 2 < Ls) tLs++; if(tRs * 2 > Rs) tRs--;
	work2(tLp, tRp, tLq, tRq, tLr, tRr, tLs, tRs);
	p = p * 2, q = q * 2, r = r * 2, s = s * 2;
}
void solve()
{
	n = read();
	ru(j1, 0, 1) ru(j2, 0, 1) ru(j3, 0, 1) lim[j1][j2][j3] = -INF;
	ru(i, 1, n)
	{
		ll x[3] = {readll(), readll(), readll()};
		ru(j1, 0, 1) ru(j2, 0, 1) ru(j3, 0, 1) lim[j1][j2][j3] = max(lim[j1][j2][j3], x[0] * (2 * j1 - 1) + x[1] * (2 * j2 - 1) + x[2] * (2 * j3 - 1));
	}
	ll LLL = 0, RRR = 3e18, m; int cnt = 0;
	while(LLL < RRR)
	{
	    //cnt++;
	    //if(cnt % 10 == 0) printf("%lld %lld\n", LLL, RRR); fflush(stdout);
		m = (LLL + RRR) / 2;
		if(check(m)) RRR = m;
		else LLL = m + 1;
	}
	work(LLL); //printf("%lld %lld %lld\n", LLL, p, r);
	printf("%lld %lld %lld\n", (p + s) / 2, (p - q) / 2, (p - r) / 2);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}