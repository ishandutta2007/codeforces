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
int n, val[maxn], ok[maxn];
vector<int> G[maxn];
ll f[maxn][2];
void dfs(int x, int fa)
{
	if((int)G[x].size() == 1 && x != 1)
	{
		f[x][0] = 0;
		f[x][1] = val[x];
		return;
	}
	for (auto V: G[x]) if(V ^ fa)
	{
		dfs(V, x);
		f[x][0] = min(f[x][0] + f[V][1], f[x][1] + f[V][0]);
		f[x][1] += f[V][1];
	}
	f[x][1] = min(f[x][1], f[x][0] + val[x]);
}
int VIS[maxn][2];
void work(int x, int fa, int tp)
{
	if(VIS[x][tp]) return;
	VIS[x][tp] = 1;
	if(G[x].size() == 1 && x != 1)
	{
		ok[x] |= tp;
		return;
	}
	ll sum = 0;
	for (auto V: G[x]) if(V ^ fa) sum += f[V][1];
	if(tp == 1)
	{	
		if(sum == f[x][1])
		{
			for (auto V: G[x]) if(V ^ fa) work(V, x, 1);
		}
		if(f[x][1] == f[x][0] + val[x]) ok[x] = 1, tp = 0;
	}
	if(tp == 0)
	{
		int cnt = 0;
		for (auto V: G[x]) if(V ^ fa)
		{
			if(f[V][0] + sum - f[V][1] == f[x][0]) cnt++, work(V, x, 0);
		}
		for (auto V: G[x]) if(V ^ fa)
		{
			if(f[V][0] + sum - f[V][1] == f[x][0] && cnt == 1) continue;
			work(V, x, 1);
		}
	}
}
vector<int> ans;
int main()
{
	n = read();
	ru(i, 1, n) val[i] = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	work(1, 0, 1);
	ru(i, 1, n) if(ok[i]) ans.push_back(i);
	printf("%lld %d\n", f[1][1], (int)ans.size());
	for (auto x: ans) printf("%d ", x);
	return 0;
}