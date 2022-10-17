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
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, tp[maxn], to[maxn], ok[maxn], f[maxn];
set<int> buc;
vector<int> G[maxn];
int vis[maxn], cnt[2];
void dfs(int x, int fl)
{
	cnt[fl ^ tp[x]]++, vis[x] = 1;
	for (auto V: G[x]) if(!vis[V]) dfs(V, fl ^ 1); 
}
int main()
{
//	freopen("input.in", "r", stdin);
	n = read();
	ru(i, 1, n)
	{
		int x = read(), y = read();
		if(x > y) tp[y] = 1, swap(x, y);
		to[x] = y, to[y] = x;
		if(x > n || y <= n) {printf("-1\n"); return 0;}
		f[i] = 1;
	}
	int mn = 2 * n + 1;
	ru(i, 1, n)
	{
		mn = min(mn, to[i]);
		f[i] &= (mn < to[i]);
	}
	int mx = 0;
	rd(i, n, 1)
	{
		mx = max(mx, to[i]);
		f[i] &= (mx > to[i]);
		if(f[i]) {printf("-1\n"); return 0;}
	}
	ru(i, 1, n)
	{
		if(!buc.empty() && *buc.begin() < to[i])
		{
			int tmp = *buc.begin();
			while(!buc.empty() && *buc.begin() < to[i])
			{
				int y = to[*buc.begin()];
				G[i].push_back(y), G[y].push_back(i);
				buc.erase(buc.begin());
			}
			buc.insert(tmp);
		}
		buc.insert(to[i]);
	}
	int ans = 0;
	ru(i, 1, n) if(!vis[i])
	{
		cnt[0] = cnt[1] = 0;
		dfs(i, 0);
		ans += min(cnt[0], cnt[1]);
	}
	printf("%d\n", ans);
	return 0;
}