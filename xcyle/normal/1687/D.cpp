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
#define maxn 2000005
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[maxn]; 
int las[maxn], nxt[maxn];
signed main()
{
	n = read();
	ru(i, 1, n) a[i] = read();
	n = unique(a + 1, a + n + 1) - a - 1;
	ru(i, 1, n) las[a[i]] = nxt[a[i]] = i;
	ru(i, 1, maxn - 1) if(!las[i]) las[i] = las[i - 1];
	nxt[maxn - 1] = n + 1;
	rd(i, maxn - 2, 0) if(!nxt[i]) nxt[i] = nxt[i + 1];
//	ru(i, 1, maxn - 1) printf("%d %d\n", las[i], nxt[i]);
	ru(i, 1, maxn - 1)
	{
		ll l = max(0ll, i * i - a[1]), r = i * i + i - a[1];
		if(r < 0) continue;
		int tmp = 0;
		ru(j, i, i + maxn / i)
		{
			int L = nxt[max(0ll, j * j - r)], R = las[min(j * j + j - l, (ll)maxn - 1)];
//			printf("%lld %lld %lld %lld %lld %lld %lld\n", i, j, L, R, n, l, r);
			if(tmp != L - 1 || R < tmp) {l += maxn; break;}
			if(L > R) continue;
			tmp = R;
			l = max(l, j * j - a[L]), r = min(r, j * j + j - a[R]);
			if(R == n) break;
		}
		if(l <= r) {printf("%lld\n", l); return 0;}
	}
	return 0;
}