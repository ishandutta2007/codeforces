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
#define maxn 1000005
using namespace std;
const int mo = 1e9 + 7;
const int inv2 = 5e8 + 4;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn];
struct node
{
	int val, id;
	inline bool operator < (const node &t) const
	{
		return val < t.val;
	}
}p[maxn];
int fa[maxn], siz[maxn], vis[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int ini[maxn];
inline int calc2(int l)
{
	int lim = (l - 1) / (k - 1);
	return ((ll)lim * l % mo + mo - (ll)(k - 1) * lim % mo * (lim + 1) % mo * inv2 % mo) % mo;
}
inline int calc(int l)
{
	return ini[l];
}
int main()
{
	n = read(), k = read();
	ru(i, 1, n) siz[i] = 1, fa[i] = i, p[i] = {a[i] = read(), i};
	sort(p + 1, p + n + 1);
	ru(i, 1, n) ini[i] = calc2(i);
	int ans = (ll)p[n].val * ini[n] % mo, cnt = 0;
	ru(i, 1, n - 1)
	{
		int pos = p[i].id;
		vis[pos] = 1;
		if(vis[pos - 1])
		{
			int t = find(pos - 1);
			cnt = (cnt + mo - calc(siz[t])) % mo;
			siz[t]++;
			cnt = (cnt + calc(siz[t])) % mo;
			fa[pos] = t;
		}
		if(vis[pos + 1])
		{
			int t = find(pos + 1);
			cnt = (cnt + mo - calc(siz[t])) % mo;
			cnt = (cnt + mo - calc(siz[find(pos)])) % mo;
			siz[find(pos)] += siz[t], fa[t] = find(pos);
			cnt = (cnt + calc(siz[find(pos)])) % mo;
		}
//		printf("%d %d\n", p[i].id, cnt);
		ans = (ans + mo - (ll)cnt * (p[i + 1].val - p[i].val) % mo) % mo;
	}
	printf("%d\n", ans);
	return 0;
}