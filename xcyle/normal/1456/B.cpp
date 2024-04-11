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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int a[100005];
int main()
{
	int n = read();
	ru(i, 1, n) a[i] = read();
	int tmp = n;
	rd(i, 30, 0)
	{
		int cnt = 0;
		while((a[tmp] >> i) & 1) cnt++, tmp--;
		if(cnt > 3) {printf("1\n"); return 0;}
	}
	int ans = n + 1;
	ru(i, 1, n) ru(j, i, n) ru(k, j + 1, n)
	{
		int x = 0, y = 0;
		ru(l, i, j) x ^= a[l];
		ru(l, j + 1, k) y ^= a[l];
		if(x > y) ans = min(ans, k - i - 1);//, printf("%d %d %d\n", i, j, k); 
	}
	if(ans > n) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}