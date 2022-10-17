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
#define maxn 3005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, vis[maxn];
vector<int> G[maxn];
int d1[maxn], d2[maxn];
void dfs(int x, int now)
{
	if(vis[x]) return;
	vis[x] = 1;
	if(d1[x]) d2[x] = now;
	else d1[x] = now;
	for (auto V: G[x]) dfs(V, now + 1);
	vis[x] = 0;
}
void dfs1(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	for (auto V: G[x]) dfs1(V);
}
int main()
{
	n = read();
	ru(i, 1, n)
	{
		vis[i] = 0;
		int x = read() + 1, y = read() + 1;
		G[x].push_back(y), G[y].push_back(x);
	}
	int cnt = 0;
	ru(i, 1, n) if((int)G[i].size() > 1)
	{
		ru(j, 1, n) vis[j] = 0; vis[i] = 1;
		dfs1(G[i][0]);
		int fl = 0;
		ru(j, 1, (int)G[i].size() - 1) fl |= vis[G[i][j]];
		cnt += fl;
	}
//	printf("%d\n", cnt);
	double ans = 0;
	ru(i, 1, n)
	{
		ru(j, 1, n) d1[j] = d2[j] = vis[j] = 0;
		dfs(i, 1);
//		printf("! %d\n", i);
		ru(j, 1, n)
		{
//			printf("%d %d %d\n", j, d1[j], d2[j]);
			if(!d2[j]) ans += 1.0 / d1[j];
			else
			{
				ans += 1.0 / d1[j] + 1.0 / d2[j] - 1.0 / ((d1[j] + d2[j] - 2 + cnt) / 2);
			}
		}
	}
	printf("%.9f\n", ans);
	return 0;
}