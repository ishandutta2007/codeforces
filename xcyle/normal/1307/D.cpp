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
#define mid ((l + r + 1) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k;
vector<int> G[maxn];
int x[maxn], y[maxn];
queue<int> q;
void bfs()
{
	ru(i, 1, n) x[i] = y[i] = n;
	x[1] = y[n] = 0;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto V: G[u])
		{
			if(x[V] > x[u] + 1) x[V] = x[u] + 1, q.push(V); 
		}
	}
	q.push(n);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto V: G[u])
		{
			if(y[V] > y[u] + 1) y[V] = y[u] + 1, q.push(V); 
		}
	}
}
int a[maxn], b[maxn];
void solve()
{
	n = read(), m = read(), k = read();
	ru (i, 1, k) b[i] = a[i] = read();
	ru(i, 1, m)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x); 
	} 
	bfs();
	sort(a + 1, a + k + 1, [](int X, int Y){return x[X] < x[Y];});
	sort(b + 1, b + k + 1, [](int X, int Y){return y[X] > y[Y];});
	int l = 1, r = x[n];
	while(l < r)
	{
		int pos = 1, ans = 0;
		pair<int, int> mx1 = make_pair(-n, 0), mx2 = make_pair(-n, 0);
		ru(i, 1, k)
		{
			while(pos <= k && x[a[i]] + y[b[pos]] >= mid - 1) 
			{
				pair<int, int> tmp = make_pair(x[b[pos]], b[pos]);
				if(tmp > mx1) mx2 = mx1, mx1 = tmp;
				else mx2 = max(mx2, tmp);
				pos++;
			}
			if(mx1.second != a[i]) ans = max(ans, y[a[i]] + mx1.first);
			else ans = max(ans, y[a[i]] + mx2.first);
		}
		if(ans >= mid - 1) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
int main()
{
	solve();
	return 0;
}