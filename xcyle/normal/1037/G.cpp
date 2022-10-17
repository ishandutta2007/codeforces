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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
int n, las[maxn][30], nxt[maxn][30], tmp[30];
int pre[maxn][30], suf[maxn][30], g[maxn];
inline int calc(int l, int r)
{
	unsigned long long st = 0;
	ru(j, 0, 25) if(nxt[l][j] <= r) st |= (1ll << (suf[l][j] ^ pre[r][j] ^ g[las[r][j]] ^ g[nxt[l][j]]));
	ru(j, 0, 31) if(!((st >> j) & 1)) return j;
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1); s[n + 1] = (char)'a' + 26;
	ru(i, 0, 25) nxt[n + 1][i] = n + 1;
	rd(i, n, 1) {ru(j, 0, 25) nxt[i][j] = nxt[i + 1][j]; nxt[i][s[i] - 'a'] = i;}
	ru(i, 1, n) {ru(j, 0, 25) las[i][j] = las[i - 1][j]; las[i][s[i] - 'a'] = i;}
	ru(i, 1, n)
	{
		ru(j, 0, 25) tmp[j] = las[i][j]; sort(tmp, tmp + 26);
		rd(j, 25, 0) if(tmp[j]) pre[i][s[tmp[j]] - 'a'] = calc(tmp[j] + 1, i);
		int tp = s[i + 1] - 'a';
		rd(j, i, las[i][tp] + 1) suf[j][tp] = calc(j, i);
		g[i + 1] = g[las[i][tp]] ^ pre[i][tp];
	}
	int q = read();
	while(q--) {int l = read(), r = read(); calc(l, r) ? puts("Alice") : puts("Bob");}
	return 0;
}