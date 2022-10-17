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
int n, a[maxn], b[maxn], vis[maxn], m, k;
int ans[maxn];
queue<int> q;
set<int> G[maxn];
int main()
{
	n = read(), m = read(), k = read();
	ru(i, 1, m)
	{
		a[i] = read(), b[i] = read();
		G[a[i]].insert(b[i]), G[b[i]].insert(a[i]);
	}
	int cnt = n;
	ru(i, 1, n) if(G[i].size() < k) q.push(i), vis[i] = 1, cnt--;
	rd(i, m, 1)
	{
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			for (auto V: G[x])
			{
				G[V].erase(x);
				if(!vis[V] && G[V].size() < k) q.push(V), vis[V] = 1, cnt--;
			}
		}
		ans[i] = cnt;
		G[a[i]].erase(b[i]); if(!vis[a[i]] && G[a[i]].size() < k) q.push(a[i]), vis[a[i]] = 1, cnt--;
		swap(a[i], b[i]);
		G[a[i]].erase(b[i]); if(!vis[a[i]] && G[a[i]].size() < k) q.push(a[i]), vis[a[i]] = 1, cnt--;
	}
	ru(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}