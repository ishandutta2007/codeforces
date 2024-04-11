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
int n, f[maxn], FA[maxn], g[maxn];
vector<int> G[maxn];
void dfs1(int x, int fa)
{
	FA[x] = fa;
	for (auto &V: G[x]) if(V == fa)
	{
		swap(V, G[x].back());
		break;
	}
	G[x].pop_back();
	for (auto V: G[x]) dfs1(V, x), f[x] = max(f[x], f[V] + 1);
}
int pre[maxn];
void dfs2(int x)
{
	pre[0] = g[x];
	ru(i, 0, (int)G[x].size() - 1)
	{
		pre[i + 1] = max(pre[i], f[G[x][i]] + 1);
	}
	int suf = g[x];
	rd(i, (int)G[x].size() - 1, 0)
	{
		g[G[x][i]] = max(suf, pre[i]) + 1;
		suf = max(suf, f[G[x][i]] + 1);
	}
	for (auto V: G[x]) dfs2(V);
}
vector<int> a;
vector<pii> t;
int cnt[maxn], mxs[maxn], ans[maxn];
int main()
{
	n = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x); 
	}
	G[1].push_back(0), dfs1(1, 0), dfs2(1);
	ru(i, 1, n)
	{
		a.clear();
		for (auto V: G[i]) a.push_back(f[V] + 1), t.push_back(mp(f[V] + 1, i));
		a.push_back(g[i]), t.push_back(mp(g[i], i));
		sort(a.begin(), a.end(), greater<int>());
		a.push_back(0);
		ru(j, 0, (int)a.size() - 1) if(j != 0 && a[j] < a[j - 1])
		{
			ans[2 * a[j - 1]] = max(ans[2 * a[j - 1]], j);
			ans[2 * a[j] + 1] = max(ans[2 * a[j] + 1], j + 1);
		}
	}
	ans[n] = 1;
	rd(i, n, 1) ans[i] = max(ans[i], ans[i + 1]);
	sort(t.begin(), t.end()); reverse(t.begin(), t.end());
	for (auto x: t)
	{
		int pos = x.se, val = x.fi;
		cnt[pos]++;
		ans[val * 2] = max(ans[val * 2], cnt[pos] + cnt[FA[pos]] - 2);
		ans[val * 2] = max(ans[val * 2], cnt[pos] + mxs[pos] - 2);
		mxs[FA[pos]] = max(mxs[FA[pos]], cnt[pos]); 
	}
	rd(i, n / 2, 1) ans[i * 2] = max(ans[i * 2], ans[(i + 1) * 2]);
	ru(i, 1, n) printf("%d ", ans[i]);
	return 0;
}