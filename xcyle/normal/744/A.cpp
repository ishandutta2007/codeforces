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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k, vis[maxn], cnt, fl, tp[maxn];
vector<int> t; int sum;
vector<int> G[maxn];
void dfs(int x)
{
	vis[x] = 1, cnt++, fl |= tp[x];
	for (auto V: G[x]) if(!vis[V]) dfs(V);
}
int main()
{
	n = read(), m = read(), k = read();
	ru(i, 1, k) tp[read()] = 1;
	ru(i, 1, m)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ru(i, 1, n) if(!vis[i])
	{
		cnt = 0, fl = 0;
		dfs(i);
		if(!fl) sum += cnt;
		else t.push_back(cnt);
	}
	sort(t.begin(), t.end(), greater<int>());
	t[0] += sum;
	int ans = 0;
	for (auto x: t) ans += x * (x - 1) / 2;
	printf("%d\n", ans - m);
	return 0;
}