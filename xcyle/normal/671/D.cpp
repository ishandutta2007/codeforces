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
#define maxn 300005
#define N 4000005
#define fi first
#define se second
using namespace std;
const ll INF = 1e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, ch[N][2], ed[maxn], tot, dep[maxn];
vector<pair<int, int> > p[maxn];
vector<int> rub;
vector<int> G[maxn];
ll t[N], tag[N], f[maxn];
void init(int x, int fa) {dep[x] = dep[fa] + 1; for (auto V: G[x]) if(V ^ fa) init(V, x);}
inline int new_node()
{
	if(!rub.empty())
	{
		int tmp = rub.back(); rub.pop_back();
		t[tmp] = INF, tag[tmp] = 0, ch[tmp][0] = ch[tmp][1] = 0;
//		printf("!");
		return tmp;
	}
	t[++tot] = INF;
	return tot;
}
inline void pushdown(int x)
{
	if(!tag[x]) return;
	tag[ch[x][0]] += tag[x], tag[ch[x][1]] += tag[x];
	tag[ch[x][0]] = min(tag[ch[x][0]], INF), tag[ch[x][1]] = min(tag[ch[x][1]], INF);
	t[ch[x][0]] += tag[x], t[ch[x][1]] += tag[x];
	t[ch[x][0]] = min(t[ch[x][0]], INF), t[ch[x][1]] = min(t[ch[x][1]], INF);
	tag[x] = 0;
}
void modify(int &x, int l, int r, int pos, ll val)
{
	if(!x) x = new_node();
	t[x] = min(t[x], val);
	if(l == r) return; pushdown(x);
	if(pos <= mid) modify(ch[x][0], l, mid, pos, val);
	else modify(ch[x][1], mid + 1, r, pos, val);
}
void clear(int x, int l, int r, int pos)
{
	if(!x) return;
	if(l == r) {t[x] = INF; return;} pushdown(x);
	if(pos <= mid) clear(ch[x][0], l, mid, pos);
	else clear(ch[x][1], mid + 1, r, pos);
	t[x] = min(t[ch[x][0]], t[ch[x][1]]);
}
inline int merge(int x, int y, int l, int r)
{
	if(!x || !y) return x + y;
	if(l == r) {t[x] = min(t[x], t[y]); return x;} pushdown(x), pushdown(y);
	ch[x][0] = merge(ch[x][0], ch[y][0], l, mid);
	ch[x][1] = merge(ch[x][1], ch[y][1], mid + 1, r);
	t[x] = min(t[ch[x][0]], t[ch[x][1]]);
	rub.push_back(y);
	return x;
}
void dfs(int x, int fa)
{
	ll sum = 0;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x), sum += f[V], sum = min(sum, INF);
	if(x == 1) {printf("%lld\n", sum); exit(0);}
	for (auto V: G[x]) if(V ^ fa)
	{
		tag[ed[V]] += sum - f[V]; tag[ed[V]] = min(tag[ed[V]], INF);
		ed[x] = merge(ed[x], ed[V], 1, n);
	}
	for (auto V: p[x]) modify(ed[x], 1, n, V.fi, min(INF, V.se + sum));
	clear(ed[x], 1, n, dep[x] + 1);
	f[x] = t[ed[x]];
	if(f[x] == INF) {printf("-1\n"); exit(0);}
}
int main()
{
	t[0] = INF;
	n = read(), m = read();
	ru(i, 1, n - 1) 
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	init(1, 0);
	ru(i, 1, m)
	{
		int x = read(), y = read(), z = read();
		if(x != y) p[x].push_back(make_pair(dep[y] + 1, z));
	}
	dfs(1, 0);
	return 0;
}