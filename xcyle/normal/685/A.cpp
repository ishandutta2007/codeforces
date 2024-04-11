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
inline int calc(int x)
{
	int res = 0;
	while(x) res++, x /= 7;
	return max(1, res);
}
int n, m, cnt[10];
int work(int x, int num)
{
	while(num--)
	{
		if(cnt[x % 7]) return 1;
		cnt[x % 7] = 1;
		x /= 7;
	}
	return 0;
}
int main()
{
	n = read() - 1, m = read() - 1;
	int C = calc(n) + calc(m);
	if(C > 7) {printf("0\n"); return 0;}
	if(n > m) swap(n, m);
	int ans = 0, tn = calc(n), tm = calc(m);
	ru(i, 0, n) 
	{
		ru(k, 0, 6) cnt[k] = 0;
		if(work(i, tn)) continue;
		ru(j, 0, m)
		{
			ru(k, 0, 6) cnt[k] = 0;
			work(i, tn);
			if(!work(j, tm)) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}