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
int n, sum[maxn];
char s[maxn];
int f[maxn][11];
inline int calc(int x)
{
	return (ll)x * (x + 1) / 2;
}
int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	sum[1] = 9;
	ru(i, 2, n) sum[i] = (calc(sum[i - 1]) + 9) % 11;
	ru(i, 0, 10) f[n + 1][i] = n;
	ll ans = 0;
	rd(i, n, 1)
	{
		ru(j, 0, 10)
		{
			if((j + 1) % 11 <= s[i] - '0') f[i][j] = i - 1;
			else f[i][j] = f[i + 1][(calc(j) + s[i] - '0' + 9) % 11];
		}
		//ru(j, 0, 10) printf("%d ", f[i][j]); printf("\n");
		if(s[i] != '0') ans += f[i + 1][s[i] - '0' - 1] - i + 1;//, printf("! %d\n", f[i + 1][s[i] - '0' - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}