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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, fl, vis[maxn], res, st[maxn], ok[maxn];
int ast1[maxn], ast2[maxn];
vector<pii> G[maxn];
vector<int> S;
char s[3];
void dfs(int x, int fa)
{
	S.push_back(x);
	ok[x] = 1;
	res += st[x];
	vis[x] = 1;
	for (auto V: G[x])
	{
		int v = V.fi, w = V.se;
		if(vis[v]) {fl &= !(st[x] ^ st[v] ^ w); continue;}
		st[v] = st[x] ^ w, dfs(v, x);
	}
}
int main()
{
	n = read(), m = read(); int ans1 = 0, ans2 = 0;
	ru(i, 1, m)
	{
		int x = read(), y = read();
		scanf("%s", s);
		G[x].push_back(mp(y, s[0] == 'B')), G[y].push_back(mp(x, s[0] == 'B'));
	}
	ru(i, 1, n) if(!ok[i])
	{
		int tmpans = n + 1;
		ru(j, 0, 1)
		{
			S.clear();
			st[i] = j, fl = 1, res = 0, dfs(i, i);
			if(fl && res < tmpans)
			{
				tmpans = res;
				for (auto x: S) ast1[x] = st[x];
			}
			for (auto x: S) vis[x] = 0;
		}
		ans1 = min(n + 1, ans1 + tmpans);
	}
	ru(i, 1, n) for (auto &v: G[i]) v.se ^= 1;
	ru(i, 1, n) ok[i] = 0;
	ru(i, 1, n) if(!ok[i])
	{
		int tmpans = n + 1;
		ru(j, 0, 1)
		{
			S.clear();
			st[i] = j, fl = 1, res = 0, dfs(i, i);
			if(fl && res < tmpans)
			{
				tmpans = res;
				for (auto x: S) ast2[x] = st[x];
			}
			for (auto x: S) vis[x] = 0;
		}
		ans2 = min(n + 1, ans2 + tmpans);
	}
	if(ans2 < ans1) 
	{
		ans1 = ans2;
		ru(i, 1, n) ast1[i] = ast2[i];
	}
	if(ans1 > n) printf("-1\n");
	else 
	{
		printf("%d\n", ans1);
		ru(i, 1, n) if(ast1[i]) printf("%d ", i);
	}
	return 0;
}