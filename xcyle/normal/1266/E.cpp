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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn];
int buc[maxn];
ll res = 0;
map<pii, int> vis;
void add(int x, int val)
{
	res += min(a[x], buc[x]);
	buc[x] += val;
	res -= min(a[x], buc[x]);
}
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read(), res += a[i];
	int q = read();
	while(q--)
	{
		int s = read(), t = read(), u = read();
		if(vis[mp(s, t)])
		{
			add(vis[mp(s, t)], -1);
			vis[mp(s, t)] = 0;
		}
		add(u, 1);
		vis[mp(s, t)] = u;
		printf("%lld\n", res);
	}
	return 0;
}