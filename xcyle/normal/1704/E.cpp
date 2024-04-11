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
#define int long long
#define maxn 1005
using namespace std;
const int mo = 998244353;
const int INF = 1e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, d[maxn], a[maxn];
vector<int> G[maxn];
int vis[maxn][maxn], mx[maxn];
void modify(int x, int y)
{
	int tmp = 0;
	if(vis[y][1002]) tmp += mx[y] - 1002;
	if(vis[x][1002]) tmp += mx[x] - 1002;
	int las = 0;
	ru(i, 1, 1002)
	{
		vis[y][i] += vis[x][i] + las;
		if(vis[y][i])
		{
			las = vis[y][i] - 1, vis[y][i] = 1;
		}
	}
	if(vis[y][1002]) mx[y] = ((1002 + tmp + las) % mo + mo) % mo;
	else
	{
		ru(i, 1, 1002) if(vis[y][i]) mx[y] = i;
	}
}
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) 
	{
		int x = read(); mx[i] = x % mo;
		ru(j, 1, 1002) vis[i][j] = 0;
		ru(j, 1, min(1002ll, x)) vis[i][j] = 1;
	}
	ru(i, 1, n) G[i].clear();
	ru(i, 1, m) 
	{
		int x = read(), y = read();
		G[x].push_back(y), d[y]++;
	}
	queue<int> q;
	ru(i, 1, n) if(!d[i]) q.push(i);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		if(G[x].size() == 0)
		{
			printf("%lld\n", mx[x] % mo); return;
		}
		mx[x] = (mx[x] + 1) % mo;
		rd(i, 1002, 1) vis[x][i] = vis[x][i - 1]; 
		for (auto V: G[x])
		{
			d[V]--;
			modify(x, V);
			if(!d[V]) q.push(V);
		}
	}
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}