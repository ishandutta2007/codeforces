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
#define maxn 505
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
int G[maxn][maxn], tp[maxn], col[maxn];
void dfs(int x)
{
	ru(V, 1, n) if(V != x && !tp[V] && col[V] == -1)
	{
		col[V] = col[x] ^ (!G[x][V]);
		dfs(V);
	}
}
int main()
{
	n = read(), m = read();
	ru(i, 1, m)
	{
		int x = read(), y = read();
		G[x][y] = G[y][x] = 1;
	}
	ru(i, 1, n)
	{
		tp[i] = 1;
		ru(j, 1, n) if(i ^ j) tp[i] &= G[i][j]; 
		col[i] = -1;
	}
	ru(i, 1, n) if(col[i] == -1 && !tp[i]) col[i] = 0, dfs(i);
	ru(i, 1, n) ru(j, 1, n) if(i != j && !tp[i] && !tp[j])
	{
		if(col[i] ^ col[j] ^ 1 != G[i][j]) {printf("No\n"); return 0;}
	}
	printf("Yes\n");
	ru(i, 1, n)
	{
		if(tp[i]) printf("b");
		else if(col[i]) printf("a");
		else printf("c");
	}
	return 0;
}