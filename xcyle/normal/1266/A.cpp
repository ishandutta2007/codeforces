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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[10005];
void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int tot = 0;
	ru(i, 1, n) tot += s[i] - '0';
	if(tot % 3 != 0)
	{
		printf("cyan\n");
		return;
	}
	int fl = 0;
	ru(i, 1, n)
	{
		fl |= (s[i] == '0');
	}
	if(!fl)
	{
		printf("cyan\n");
		return;
	}
	int cnt = 0;
	ru(i, 1, n) if((s[i] - '0') % 2 == 0) cnt++;
	if(cnt >= 2 || n == 1)
	{
		printf("red\n");
	}
	else printf("cyan\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}