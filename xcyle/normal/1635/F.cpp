/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 300005
using namespace std;
const ll INF = 4e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, sta[maxn], top;
ll t[maxn], ans[maxn], x[maxn], w[maxn];
vector<pair<int, ll> > pos[maxn];
vector<pair<int, int> > que[maxn];
inline void modify(int x, ll d){for (; x <= n; x += x & -x) t[x] = min(t[x], d);}
inline ll query(int x){ll res = INF; for (; x; x -= x & -x) res = min(res, t[x]); return res;}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) x[i] = read(), w[i] = read();
	sta[top = 0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while(top && w[sta[top]] > w[i]) top--;
		pos[sta[top]].push_back(make_pair(i, (x[i] - x[sta[top]]) * (w[i] + w[sta[top]])));
		sta[++top] = i;
	}
	sta[top = 0] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		while(top && w[sta[top]] > w[i]) top--;
		pos[i].push_back(make_pair(sta[top], (x[sta[top]] - x[i]) * (w[i] + w[sta[top]])));
		sta[++top] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int l = read(),  r = read();
		que[l].push_back(make_pair(r, i));
	}
	for (int i = 1; i <= n; i++) t[i] = INF;
	for (int i = n; i >= 1; i--)
	{
		for (auto x: pos[i]) if(x.first) modify(x.first, x.second);
		for (auto x: que[i]) ans[x.second] = query(x.first);
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}