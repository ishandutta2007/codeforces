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
#define maxn 20005
#define maxk 15 
#define N 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k, num, id[maxn][maxk][2];
vector<int> G[N];
int tot, dfn[N], low[N], col[N], vis[N], sta[N], top, cnt;
inline void add(int a1, int b1, int c1, int a2, int b2, int c2)
{
	if((b2 > k && !c2) || (b2 < 1 && c2)) return;
	if((b2 > k && c2) || (b2 < 1 && !c2)) a2 = a1, b2 = b1, c2 = c1 ^ 1;  
//	printf("%d %d %d %d %d %d\n", a1, b1, c1, a2, b2, c2);
	G[id[a1][b1][c1]].push_back(id[a2][b2][c2]);
	G[id[a2][b2][c2 ^ 1]].push_back(id[a1][b1][c1 ^ 1]);
}
void tar(int x)
{
	dfn[x] = low[x] = ++tot;
	vis[x] = 1, sta[++top] = x;
	for (auto V: G[x])
	{
		if(!dfn[V]) tar(V), low[x] = min(low[x], low[V]);
		else if(vis[V]) low[x] = min(low[x], dfn[V]);
	}
	if(dfn[x] == low[x])
	{
		vis[x] = 0, col[x] = ++cnt;
		while(sta[top] != x) vis[sta[top]] = 0, col[sta[top]] = cnt, top--;
		top--;
	} 
}
void solve()
{
	ru(i, 1, num) dfn[i] = 0, G[i].clear(); cnt = tot = num = 0;
	n = read(), m = read(), k = read();
	ru(i, 1, n) ru(j, 1, k) ru(c, 0, 1) id[i][j][c] = ++num; 
	ru(i, 1, n) add(i, 1, 0, i, 1, 1);
	ru(i, 2, n) ru(j, 1, k) add(i - 1, j, 1, i, j, 1);
	ru(i, 1, n) ru(j, 2, k) add(i, j, 1, i, j - 1, 1);
	ru(i, 1, m)
	{
		int tp = read(), a = read();
		if(tp == 1)
		{
			int x = read();
			add(a, x, 1, a, x + 1, 1);
		}
		else
		{
			int b = read(), x = read();
			ru(y, 1, k) add(a, y, tp ^ 3, b, x - y + 1, tp ^ 2);
		}
	}
	ru(i, 1, num) if(!dfn[i]) tar(i);
	ru(i, 1, n) ru(j, 1, k) if(col[id[i][j][0]] == col[id[i][j][1]]) {printf("-1\n"); return;}
	ru(i, 1, n)
	{
		int res = 0;
		ru(j, 1, k) res += (col[id[i][j][1]] < col[id[i][j][0]]);//, printf("%d %d\n", col[id[i][j][1]], col[id[i][j][0]]);
		printf("%d ", res);
	}
	printf("\n");
}
int main()
{
	int T = read(); while(T--) solve(); 
	return 0;
}