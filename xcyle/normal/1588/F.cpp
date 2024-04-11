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
#define maxn 200005
#define B 300
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
ll suma[maxn], add[3 * B + 5];
int n, q, p[maxn], pf[maxn];
int tp[maxn], x[maxn], y[maxn], top;
int vis[maxn], bel[maxn], buc[3 * B + 5], id[maxn];
int tim[B + 5][3 * B + 5];
vector<int> L[maxn], R[maxn];
ll t[maxn];
inline void Add(int x, int v) {for (; x <= n; x += x & (-x)) t[x] += v;}
inline ll que(int x) {ll res = 0; for (; x; x -= x & (-x)) res += t[x]; return res;}
void solve()
{
	memset(buc, 0, sizeof(buc));
	memset(tim, 0, sizeof(tim)); 
	memset(add, 0, sizeof(add)); 
	ru(i, 1, n) L[i].clear(), R[i].clear(), pf[p[i]] = i, bel[i] = vis[i] * i;
	ru(i, 1, top) if(tp[i] == 1) L[x[i] - 1].push_back(i), R[y[i]].push_back(i);
	int cnt = 0;
	ru(i, 1, n) if(vis[i])
	{
		id[bel[i] = i] = ++cnt;
		for (int now = pf[i]; !bel[now]; now = pf[now]) bel[now] = i;
	}
	ru(i, 1, n) if(!bel[i])
	{
		id[bel[i] = i] = ++cnt;
		int tot = 1;
		for (int now = pf[i]; !bel[now]; now = pf[now]) bel[now] = i, tot++;
		if(tot <= n / B) id[i] = 0, cnt--;
	}
	ru(i, 1, n)
	{
		buc[id[bel[i]]]++;
		for (auto x: L[i]) ru(j, 1, cnt) tim[x][j] -= buc[j];
		for (auto x: R[i]) ru(j, 1, cnt) tim[x][j] += buc[j];
	}
	ru(i, 1, top)
	{
		if(tp[i] == 1)
		{
			ll ans = suma[y[i]] - suma[x[i] - 1] + que(y[i]) - que(x[i] - 1);
			ru(j, 1, cnt) ans += (ll)tim[i][j] * add[j];
			printf("%lld\n", ans);
		}
		if(tp[i] == 2)
		{
			if(!id[bel[x[i]]])
			{
				Add(x[i], y[i]);
				for (int j = p[x[i]]; j != x[i]; j = p[j]) Add(j, y[i]);
				continue;
			}
			add[id[x[i] = bel[x[i]]]] += y[i];
			for (int j = bel[p[x[i]]]; j != x[i]; j = bel[p[j]]) add[id[j]] += y[i];
		}
		if(tp[i] == 3) vis[x[i]] = vis[y[i]] = 0, swap(p[x[i]], p[y[i]]);
	}
	ll sum = 0;
	ru(i, 1, n) sum += add[id[bel[i]]], suma[i] += sum; 
	top = 0;
}
int main()
{
	n = read();
	ru(i, 1, n) suma[i] = suma[i - 1] + read();
	ru(i, 1, n) p[i] = read();
	q = read();
	while(q--)
	{
		top++, tp[top] = read(), x[top] = read(), y[top] = read();
		if(tp[top] == 3) vis[x[top]] = vis[y[top]] = 1;
		if(q % B == 0) solve();
	}
	return 0;
}