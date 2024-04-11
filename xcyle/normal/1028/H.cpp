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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 1100005
#define maxa 5100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int vis[maxa], pri[maxa][8], f[maxa];
void init()
{
	ru(i, 2, maxa - 1) if(!vis[i])
	{
		pri[i][f[i]++] = i;
		for (int j = 2 * i; j < maxa; j += i) vis[j] = 1, pri[j][f[j]++] = i;
	}
}
int n, q, a[maxn], ans[maxn];
vector<pii> que[maxn];
int las[maxa][8], pos[15];
int main()
{
	init();
	n = read(), q = read();
	ru(i, 1, n) 
	{
		a[i] = read();
		int tmp = a[i];
		ru(j, 0, f[tmp] - 1)
		{
			int x = pri[tmp][j];
			if(x * x > a[i]) break;
			while(a[i] % (x * x) == 0) a[i] /= (x * x); 
		}
	}
	ru(i, 1, q)
	{
		int l = read(), r = read();
		que[r].push_back(mp(l, i));
	}
	ru(i, 1, n)
	{
		ru(j, 0, (1 << f[a[i]]) - 1)
		{
			int x = 1;
			ru(k, 0, f[a[i]] - 1) if((j >> k) & 1) x *= pri[a[i]][k];
			int rem = f[a[i] / x];
			ru(k, 0, 7) pos[rem + k] = max(pos[rem + k], las[x][k]);
			las[x][rem] = i;
		}
		for (auto t: que[i])
		{
			ru(j, 0, 14) if(pos[j] >= t.fi) {ans[t.se] = j; break;}
		}
	}
	ru(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}