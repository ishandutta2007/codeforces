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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], now[maxn], ans;
int adj[maxn], nxt[maxn];
void solve()
{
	scanf("%d%d", &n, &k);
	ru(i, 1, n) scanf("%d", &a[i]); 
	int mx = 0; ans = 1e6;
	ru(i, 0, maxn - 1) adj[i] = nxt[i] = 0;
	ru(i, 1, n) mx = max(mx, now[i] = a[i] / k), nxt[i] = adj[now[i]], adj[now[i]] = i;
	ru(i, 0, maxn - 1) while(adj[i])
	{
		int x = adj[i]; adj[i] = nxt[x];
		ans = min(ans, mx - now[x]);
		if(a[x] == now[x]) {printf("%d\n", ans); return;}
		now[x] = a[x] / (a[x] / (now[x] + 1));
		nxt[x] = adj[now[x]], adj[now[x]] = x, mx = max(mx, now[x]);
	}
	printf("%d\n", ans);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}