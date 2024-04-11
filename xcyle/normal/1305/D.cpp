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
int n, d[maxn], vis[maxn];
vector<int> G[maxn];
queue<int> q;
int main()
{
	n = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
		d[x]++, d[y]++;
	}
	ru(i, 1, n) if(d[i] == 1) q.push(i), vis[i] = 1;
	while(q.size() > 1)
	{
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		printf("? %d %d\n", x, y); fflush(stdout);
		int c = read();
		if(c == x || c == y) {printf("! %d\n", c); fflush(stdout); return 0;}
		for (auto V: G[x]) if(!vis[V])
		{
			d[V]--;
			if(d[V] <= 1)
			{
				q.push(V), vis[V] = 1;
			}
		}
		for (auto V: G[y]) if(!vis[V])
		{
			d[V]--;
			if(d[V] <= 1)
			{
				q.push(V), vis[V] = 1;
			}
		}
	}
	printf("! %d\n", q.front()); fflush(stdout);
	return 0;
}