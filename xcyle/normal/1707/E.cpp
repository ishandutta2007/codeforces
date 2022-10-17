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
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define B 20
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, a[maxn], LOG[maxn];
pii f[maxn][B + 5];
int stl[maxn][B + 5][20], str[maxn][B + 5][20];
inline pii query(pii x, int lev)
{
	int l = x.fi, r = x.se - 1, len = LOG[r - l + 1];
	if(l > r) return x;
	int L = min(stl[l][lev][len], stl[r - (1 << len) + 1][lev][len]);
	int R = max(str[l][lev][len], str[r - (1 << len) + 1][lev][len]);
	return mp(L, R);
}
int main()
{
	ru(i, 2, maxn - 1) LOG[i] = LOG[i >> 1] + 1;
	n = read(), q = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n - 1) ru(j, 0, B) ru(k, 0, 18) stl[i][j][k] = n + 1; 
	ru(i, 0, B)
	{
		rd(j, n - 1, 1)
		{
			if(!i) f[j][i] = mp(min(a[j], a[j + 1]), max(a[j], a[j + 1]));
			else f[j][i] = query(f[j][i - 1], i - 1);
			stl[j][i][0] = f[j][i].fi, str[j][i][0] = f[j][i].se;
//			printf("%d %d %d %d\n", i, j, stl[j][i][0], str[j][i][0]);
			ru(k, 1, 18) if(j + (1 << k) - 1 < n)
			{
				stl[j][i][k] = min(stl[j][i][k - 1], stl[j + (1 << (k - 1))][i][k - 1]);
				str[j][i][k] = max(str[j][i][k - 1], str[j + (1 << (k - 1))][i][k - 1]);
			}
		}
	}
	ru(i, 1, q)
	{
		int x = read(), y = read();
		if(x == 1 && y == n) {printf("0\n"); continue;}
		pii now = mp(x, y);
		ll ans = 0;
		rd(i, B, 0)
		{
			pii nxt = query(now, i);
			if(nxt.fi == 1 && nxt.se == n) continue;
			ans |= (1ll << i);
			now = nxt;
		} 
		if(ans > (1ll << B)) printf("-1\n");
		else printf("%lld\n", ans + 1);
	}
	return 0;
}