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
#define maxn 5000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn], buc[maxn], mx[maxn], cnt[maxn];
void solve()
{
	n = read(), m = read();
	ru(i, 1, m) buc[i] = mx[i] = cnt[i] = 0; cnt[0] = n;
	ru(i, 1, n) buc[read()]++;
	int ans = m, l = 0;
	ru(r, 1, m)
	{
		cnt[mx[r]] -= buc[r];
		mx[r] = r;
		cnt[mx[r]] += buc[r];
		ru(i, 2, m / r)
		{
			cnt[mx[i * r]] -= buc[i * r];
			mx[i * r] = max(mx[i * r], mx[i]);
			cnt[mx[i * r]] += buc[i * r];
		}
		while(!cnt[l]) l++;
		if(l) ans = min(ans, r - l);
	}
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}