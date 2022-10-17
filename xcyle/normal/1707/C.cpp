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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, anc[maxn][22], u[maxn], v[maxn], dfn[maxn], out[maxn], tot, dep[maxn];
int FA[maxn]; inline int find(int x) {return x == FA[x] ? x : FA[x] = find(FA[x]);}
vector<int> G[maxn];
void init(int x, int fa)
{
	dep[x] = dep[fa] + 1, dfn[x] = ++tot;
	anc[x][0] = fa; ru(i, 1, 20) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (auto V: G[x]) if(V ^ fa) init(V, x);
	out[x] = tot;
}
int jump(int x, int y)
{
	rd(i, 20, 0) if((y >> i) & 1) x = anc[x][i];
	return x;
}
int sum[maxn];
inline void add(int x, int v)
{
	sum[x] += v;
}
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) FA[i] = i;
	int cnt = 0;
	ru(i, 1, m) 
	{
		int x = read(), y = read();
		if(find(x) == find(y)) cnt++, u[cnt] = x, v[cnt] = y;
		else FA[find(x)] = find(y), G[x].push_back(y), G[y].push_back(x);
	}
	init(1, 0);
	ru(i, 1, cnt)
	{
		if(dep[u[i]] > dep[v[i]]) swap(u[i], v[i]);
		add(dfn[v[i]], 1), add(out[v[i]] + 1, -1);
		if(dfn[u[i]] <= dfn[v[i]] && dfn[v[i]] <= out[u[i]])
		{
			int tmp = jump(v[i], dep[v[i]] - dep[u[i]] - 1);
			add(1, 1), add(dfn[tmp], -1), add(out[tmp] + 1, 1);
		}
		else add(dfn[u[i]], 1), add(out[u[i]] + 1, -1);
	}
	ru(i, 1, n) 
	{
		sum[i] += sum[i - 1];
		
	}
	ru(i, 1, n) printf("%d", (sum[dfn[i]] == cnt ? 1 : 0));
}
int main()
{
	solve();
	return 0;
}