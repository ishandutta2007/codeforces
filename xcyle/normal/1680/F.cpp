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
#define maxn 1000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, dep[maxn], vis[maxn];
ll sum[maxn], cnt, fat[maxn];
vector<int> G[maxn];
int a, b;
void dfs(int x, int fa)
{
	fat[x] = fa;
	vis[x] = 1, dep[x] = dep[fa] + 1;
	for (auto V: G[x])
	{
		if(!vis[V] && V != fa) dfs(V, x), sum[x] += sum[V];
		else if(dep[V] <= dep[x])
		{
			if((dep[x] & 1) == (dep[V] & 1))
			{
//				printf("! %d %d\n", x, V);
				sum[x]++, sum[V]--, cnt++;//, sum[lca(x, V)] -= 2, cnt++;
				a = x, b = V;
			}
			else if(V ^ fa)
			{
				sum[x] -= INF, sum[V] += INF;
			}
		}
	}
}
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) vis[i] = sum[i] = 0, G[i].clear(); cnt = 0;
	ru(i, 1, m)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	if(!cnt)
	{
		printf("YES\n");
		ru(i, 1, n) printf("%d", dep[i] & 1); printf("\n");
	}
	else
	{
		ru(i, 1, n) vis[i] = 0;
		if(cnt == 1) dep[b] = 0, dfs(a, b);
		else
		{
			int pos = 0;
			ru(i, 2, n) if(sum[i] == cnt) pos = i;
//			ru(i, 1, n) printf("%d ", sum[i]); printf("%d\n", pos);
			if(!pos) {printf("NO\n", cnt); return;}
			dep[fat[pos]] = 0, dfs(pos, fat[pos]);
		}
		printf("YES\n");
		ru(i, 1, n) printf("%d", dep[i] & 1); printf("\n");
	}
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}