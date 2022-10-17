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
#define maxn 200005
using namespace std;
const ll INF = 9e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
ll a[maxn];
struct node
{
	ll l, r;
	inline bool friend operator < (node xx, node yy)
	{
		return xx.l == yy.l ? xx.r < yy.r : xx.l < yy.l;
	}
}p[maxn], tmp[maxn];
ll L[maxn], R[maxn];
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	a[++n] = -INF;
	a[++n] = INF;
	sort(a + 1, a + n + 1);
	int temp = m;
	m = 0;
	for (int i = 1; i <= temp; i++)
	{
		m++;
		scanf("%lld%lld", &p[m].l, &p[m].r);
		int loc = lower_bound(a + 1, a + n + 1, p[m].l) - a;
		if(a[loc] <= p[m].r) m--;
	}
	sort(p + 1, p + m + 1);
//	for (int i = 1; i <= m; i++) printf("%lld %lld\n", p[i].l, p[i].r);
	ll mn = INF;
	for (int i = m; i >= 1; i--)
	{
		mn = min(mn, p[i].r);
		p[i].r = mn;
	}
	p[0].r = -2ll * INF;
	ll f0 = -2ll * a[1], f1 = -a[1], f;
	int L = 0, R = 0;
	for (int i = 1; i < n; i++)
	{
		ll nxf0 = INF, nxf1 = INF;
		tmp[L].l = tmp[L].r = a[i];
		while(p[R].r <= a[i + 1] && R <= m)
		{
			R++;
			tmp[R] = p[R];
		}
		tmp[R] = {a[i + 1], a[i + 1]};
//		printf("\n");
//		for (int j = L; j <= R; j++) printf("%lld %lld\n", tmp[i].l, tmp[i].r);
		for (int j = L; j < R; j++)
		{
			f = min(f0 + tmp[j].l + a[i], f1 + 2ll * tmp[j].l - a[i]);
			nxf0 = min(nxf0, f - 2ll * tmp[j + 1].r);
			nxf1 = min(nxf1, f - tmp[j + 1].r);
		}
		f0 = nxf0, f1 = nxf1;
		R--;
		L = R;
	}
	printf("%lld\n", min(f0 + 2ll * a[n], f1 + a[n]));
}
int T;
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}