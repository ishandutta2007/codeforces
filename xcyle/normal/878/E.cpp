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
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, a[maxn], fa[maxn], sum[maxn], ans[maxn];
int pw[maxn], pwi[maxn], suf[maxn];
vector<pii> que[maxn];
vector<int> G[maxn];
int t[maxn]; set<int> anc;
inline void add(int x, int v)
{
	x = n - x + 1;
	if(!x) return;
	for (; x <= n; x += x & -x) t[x] = (t[x] + v) % mo;
}
inline int query(int x)
{
	x = n - x + 1; int res = 0;
	for (; x; x -= x & -x) res = (res + t[x]) % mo;
	return res;
}
void dfs(int x)
{
	anc.insert(x + 1);
	add(x + 1, (ll)(mo + 1 - pw[x - fa[x]]) * suf[x + 1] % mo);
	for (auto t: que[x])
	{
		int l = t.fi, id = t.se;
		int pos = (*anc.lower_bound(l)) - 1;
		int tmp = (query(l) + mo - suf[x + 1]) % mo;
		tmp = (tmp + (ll)(pw[pos - fa[pos]] + mo - pw[pos + 1 - l]) * suf[pos + 1] % mo) % mo;
//		printf("!! %d\n", tmp);
		ans[id] = (ans[id] + (ll)2 * tmp % mo) % mo;
	}
	for (auto V: G[x]) dfs(V);
	anc.erase(x + 1);
	add(x + 1, (ll)(mo - 1 + pw[x - fa[x]]) * suf[x + 1] % mo);
}
int main()
{
	n = read(), q = read();
	pw[0] = pwi[0] = 1;
	ru(i, 1, n) a[i] = read(), pw[i] = pw[i - 1] * 2 % mo, pwi[i] = (ll)pwi[i - 1] * ((mo + 1) / 2) % mo;
	rd(i, n, 1) suf[i] = (suf[i + 1] * 2 % mo + (a[i] + mo) % mo) % mo;
	ru(i, 1, n)
	{
		fa[i] = i - 1, sum[i] = a[i];
		while(fa[i] && sum[i] > 0)
		{
			if(fa[i] - fa[fa[i]] >= 30) {fa[i] = 0; break;}
			ll tmp = (ll)sum[i] * pw[fa[i] - fa[fa[i]]] + sum[fa[i]];
			if(tmp >= 1e9) {fa[i] = 0; break;}
			sum[i] = tmp, fa[i] = fa[fa[i]];
		}
		sum[i] = min(sum[i], 0);
		G[fa[i]].push_back(i);
//		printf("%d ", fa[i]);
	}
//	printf("\n");
	ru(i, 1, q)
	{
		int l = read(), r = read();
		ans[i] = (a[l++] + mo) % mo;
		if(l > r) continue;
		que[r].push_back(mp(l, i));
		ans[i] = (ans[i] + (ll)2 * suf[l] % mo) % mo;
	}
	for (auto V: G[0]) dfs(V);
	ru(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}