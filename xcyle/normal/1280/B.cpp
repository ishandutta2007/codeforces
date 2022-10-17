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
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[65][65];
int n, m;
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) scanf("%s", s[i] + 1);
	int fl = 1;
	ru(i, 1, n) ru(j, 1, m) fl &= (s[i][j] == 'A');
	if(fl) {printf("0\n"); return;}
	fl = 1;
	ru(i, 1, m) fl &= (s[1][i] == 'A');
	if(fl) {printf("1\n"); return;}
	fl = 1;
	ru(i, 1, m) fl &= (s[n][i] == 'A');
	if(fl) {printf("1\n"); return;}
	fl = 1;
	ru(i, 1, n) fl &= (s[i][1] == 'A');
	if(fl) {printf("1\n"); return;}
	fl = 1;
	ru(i, 1, n) fl &= (s[i][m] == 'A');
	if(fl) {printf("1\n"); return;}
	ru(i, 1, n) 
	{ 
		fl = 1;
		ru(j, 1, m) fl &= (s[i][j] == 'A');
		if(fl) {printf("2\n"); return;}
	}
	ru(i, 1, m) 
	{ 
		fl = 1;
		ru(j, 1, n) fl &= (s[j][i] == 'A');
		if(fl) {printf("2\n"); return;}
	}
	if(s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') {printf("2\n"); return;}
	ru(i, 1, m) fl |= s[1][i] == 'A'; 
	ru(i, 1, m) fl |= s[n][i] == 'A'; 
	ru(i, 1, n) fl |= s[i][1] == 'A'; 
	ru(i, 1, n) fl |= s[i][m] == 'A'; 
	if(fl) {printf("3\n"); return;}
	ru(i, 1, n) ru(j, 1, m) if(s[i][j] == 'A') {printf("4\n"); return;}
	printf("MORTAL\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}