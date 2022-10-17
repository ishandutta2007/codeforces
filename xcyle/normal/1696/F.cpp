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
#define maxn 105
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, fa[maxn * maxn], siz[maxn * maxn], d[maxn][maxn], st[maxn][maxn][maxn]; char s[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void solve()
{
	n = read();
	ru(i, 1, n) ru(j, 1, n) fa[(i - 1) * n + j] = (min(i, j) - 1) * n + max(i, j), siz[(i - 1) * n + j] = 1 + (i < j);
	ru(i, 1, n) ru(j, i + 1, n)
	{
		scanf("%s", s + 1);
		ru(k, 1, n) st[i][j][k] = s[k] - '0';
		ru(k, 1, n) if(st[i][j][k])
		{
			int x = find((i - 1) * n + k), y = find((j - 1) * n + k);
			if(x != y) fa[x] = y, siz[y] += siz[x];
		}
	}
	ru(fl, 1, n * n) if(find(fl) == fl && siz[fl] == 2 * (n - 1)) 
	{
		ru(i, 1, n) ru(j, 1, n) d[i][j] = (i == j) ? 0 : n + 1;
		ru(i, 1, n * n) if(find(i) == fl) d[(i - 1) / n + 1][(i - 1) % n + 1] = 1;
		ru(i, 1, n) ru(j, 1, n) ru(k, 1, n) d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
		int F = 1;
		ru(i, 1, n) ru(j, 1, n) F &= (d[i][j] < n);
		if(!F) continue;
		ru(i, 1, n) ru(j, i + 1, n) ru(k, 1, n) F &= ((d[i][k] == d[j][k]) == st[i][j][k]);
		if(!F) continue;
		printf("Yes\n");
		ru(i, 1, n) ru(j, i + 1, n) if(d[i][j] == 1) printf("%d %d\n", i, j);
		return;
	}
	printf("No\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}