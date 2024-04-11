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
#define maxn 320005
#define double long double
#define int long long
using namespace std;
const double INF = 1e18;
const double eps = 1e-15;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
int sta[maxn], fl, tp[maxn], top, tot;
vector<int> G[maxn];
ll v[maxn], t[maxn];
void dfs(int x)
{
	if(!G[x].size()) {v[x] = 1; return;}
	if(!tp[x])
	{
		v[x] = INF;
		for (auto V: G[x]) dfs(V), v[x] = min(v[x], v[V]);
	}
	else for (auto V: G[x]) dfs(V), v[x] += v[V];
}
void work(int x, int r)
{
	if(!G[x].size()) {t[x] = r; return;}
	if(!tp[x])
	{
		for (auto V: G[x]) if(v[x] == v[V]) {work(V, r); return;}
	}
	else for (auto V: G[x]) work(V, r);
}
void solve()
{
	ru(i, 1, tot) G[i].clear(), t[i] = v[i] = 0;
	int r = read(); tot = 0; fl = 1;
	while(1)
	{
		char ch = getchar();
		if(ch == '\n' || ch == '\r') break;
		if(ch == ' ') continue;
		if(ch == '(') G[sta[top]].push_back(++tot), sta[++top] = tot;
		if(ch == '*') G[sta[top]].push_back(++tot);
		if(ch == 'P') tp[sta[top]] = 1;
		if(ch == 'S') tp[sta[top]] = 0;
		if(ch == ')') top--;
	}
	assert(!top);
	dfs(1);
	work(1, r * v[1]);
	if(!fl) printf("LOSS\n");
	else
	{
		printf("REVOLTING ");
		ru(i, 1, tot) if(!G[i].size()) printf("%lld ", t[i]);
		printf("\n");
	}
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}