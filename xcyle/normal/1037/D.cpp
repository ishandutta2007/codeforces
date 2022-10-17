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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, vis[200005];
vector<int> G[200005];
int fa[200005], a[200005], pos[200005];
int b[200005], tot;
void dfs(int x)
{
	sort(G[x].begin(), G[x].end(), [](int x, int y) {return pos[x] < pos[y];});
	for (auto V: G[x]) if(V ^ fa[x]) fa[V] = x, dfs(V);
}
queue<int> q;
int main()
{
	n = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	ru(i, 1, n) pos[a[i] = read()] = i;
	dfs(1);
	q.push(1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		b[++tot] = x, vis[x] = 1;
		for (auto V: G[x]) if(!vis[V]) q.push(V);
	}
	ru(i, 1, n) if(a[i] != b[i]) {printf("No\n"); return 0;}
	printf("Yes\n");
	return 0;
}