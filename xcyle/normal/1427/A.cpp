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
int n, a[55];
void solve()
{
	n = read();
	int sum = 0;
	ru(i, 1, n) a[i] = read(), sum += a[i];
	if(sum == 0) {printf("NO\n"); return;}
	sort(a + 1, a + n + 1);
	printf("YES\n");
	if(sum > 0)
	{
		rd(i, n, 1) printf("%d ", a[i]);
	}
	else
	{
		ru(i, 1, n) printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}