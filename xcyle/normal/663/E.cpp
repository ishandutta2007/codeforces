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
#define maxn 21
#define maxm 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
char s[maxn][maxm];
int a[1 << 20];
int f[1 << 20][maxn];
int main()
{
	n = read(), m = read();
	ru(i, 0, n - 1) scanf("%s", s[i] + 1);
	ru(j, 1, m)
	{
		int st = 0;
		ru(i, 0, n - 1) st |= (s[i][j] - '0') << i; 
		f[st][0]++;
	}
	ru(i, 0, n - 1) rd(k, i + 1, 1)
	{
		ru(j, 0, (1 << n) - 1)
		{
			f[j][k] += f[j ^ (1 << i)][k - 1];
		}
	}
	int ans = n * m;
	ru(i, 0, (1 << n) - 1)
	{
		int res = 0;
		ru(j, 0, n) res += f[i][j] * min(j, n - j);
		ans = min(ans, res); 
	}
	printf("%d\n", ans);
	return 0;
}