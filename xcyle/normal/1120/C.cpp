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
#define mid ((l + r + 1) >> 1)
#define maxn 5005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a, b;
char s[maxn];
int f[maxn], lcp[maxn][maxn];
int main()
{
	n = read(), a = read(), b = read();
	scanf("%s", s + 1);
	rd(i, n, 1) rd(j, n, 1)
	{
		if(s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
	}
	ru(i, 1, n) f[i] = a * i;
	ru(i, 1, n)
	{
		int len = 0;
		ru(j, 1, i) len = max(len, min(lcp[i + 1][j], i - j + 1));
		f[i + 1] = min(f[i + 1], f[i] + a);
		f[i + len] = min(f[i + len], f[i] + b);
	}
	printf("%d\n", f[n]);
	return 0;
}