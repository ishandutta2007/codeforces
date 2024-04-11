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
#define maxn 300005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
char s[10];
inline int que(int x, int y)
{
	printf("1 %d %d\n", x, y); fflush(stdout);
	scanf("%s", s + 1);
	if(s[1] == 'T') return 1;
	else return 0;
}
int main()
{
	n = read(), k = read();
	int l = 1, r = n;
	while(l < r)
	{
		int mid = (l + r + 1) / 2;
		if(que(mid - 1, mid)) r = mid - 1;
		else l = mid;
	}
	int x = l, y;
	l = 1, r = x - 1;
	while(l < r)
	{
		int mid = (l + r + 1) / 2;
		if(que(mid - 1, mid)) r = mid - 1;
		else l = mid;
	}
	if(que(l, x)) y = l;
	l = x + 1, r = n;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(que(mid, mid + 1)) r = mid;
		else l = mid + 1;
	}
	if(que(l, x)) y = l;
	printf("2 %d %d\n", x, y);
	return 0;
}