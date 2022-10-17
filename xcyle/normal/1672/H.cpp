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
#define rd(i, l, r) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, sum[2][maxn];
char s[maxn];
int main()
{
	scanf("%d%d%s", &n, &q, s + 1);
	for (int i = 1; i <= n; i++) sum[0][i] = sum[0][i - 1], sum[1][i] = sum[1][i - 1], sum[s[i] - '0'][i] += (s[i] == s[i - 1]);
	while(q--)
	{
		int l = read(), r = read();
		int cnt[2] = {sum[0][r] - sum[0][l - 1], sum[1][r] - sum[1][l - 1]};
		cnt[s[l] - '0'] -= (s[l] == s[l - 1]);
		printf("%d\n", max(cnt[0], cnt[1]) + 1);
	}
	return 0;
}