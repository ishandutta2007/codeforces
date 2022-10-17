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
#define maxn 100005
#define B 505
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
int vis[30][30][30];
int n;
int f[maxn][2];
int check(int x, int l)
{
	ru(i, 0, l + 1)
	{
		if(s[x + i] != s[x + l + 2 + i]) return 0;
	}
	return 1;
} 
void init()
{
	f[n - 1][0] = 1, f[n - 2][1] = 1;
	rd(i, n - 3, 1)
	{
		if((!check(i, 0) && f[i + 2][0]) || f[i + 2][1]) f[i][0] = 1;
		if((!check(i, 1) && f[i + 3][1]) || f[i + 3][0]) f[i][1] = 1;
	}
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	init();
	ru(i, 6, n - 1)
	{
		if(f[i][0]) vis[s[i] - 'a' + 1][s[i + 1] - 'a' + 1][0] = 1;
		if(f[i][1]) vis[s[i] - 'a' + 1][s[i + 1] - 'a' + 1][s[i + 2] - 'a' + 1] = 1;
	}
	int ans = 0;
	ru(i, 0, 26) ru(j, 0, 26) ru(k, 0, 26) ans += vis[i][j][k];
	printf("%d\n", ans);
	ru(i, 0, 26) ru(j, 0, 26) ru(k, 0, 26) if(vis[i][j][k])
	{
		printf("%c%c", 'a' + i - 1, 'a' + j - 1);
		if(k) printf("%c", 'a' + k - 1);
		printf("\n");
	}
	return 0;
}