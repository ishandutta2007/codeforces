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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
char s[maxn];
int check()
{
	int sum = 0;
	ru(i, 1, 2 * n)
	{
		if(s[i] == '(') sum++;
		else sum--;
		if(sum < 0) return 0;
	}
	return 1;
}
void solve()
{
	scanf("%d%s", &n, s + 1);
	if(check()) {printf("0\n"); return;}
	int pos = 0, sum = 0, mx = 0;
	ru(i, 1, 2 * n)
	{
		if(s[i] == '(') sum++;
		else sum--;
		if(sum >= mx) mx = sum, pos = i;
	}
	sum = 0, mx = 0; int l = 0, r = 2 * n + 1;
	ru(i, 1, 2 * n)
	{
		if(s[i] == '(') sum++;
		else sum--;
		if(sum >= mx) mx = sum, l = i;
		if(sum < 0) break;
	}
	sum = mx = 0;
	rd(i, 2 * n, 1)
	{
		if(s[i] == ')') sum++;
		else sum--;
		if(sum >= mx) mx = sum, r = i;
		if(sum < 0) break;
	}
	l++, r--;
	for (int i = l; i <= (l + r) / 2; i++) swap(s[i], s[l + r - i]);
	if(check()) {printf("1\n%d %d\n", l, r); return;}
	
	printf("2\n1 %d\n%d %d\n", pos, pos + 1, 2 * n);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}