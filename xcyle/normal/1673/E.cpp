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
#define maxn (1 << 21)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
inline int calc(int x, int y)
{
	if(x < 0 || x < y) return 0;
	int now = x, ans = 1;
	rd(i, 20, 0) if((x >> i) & 1)
	{
		if(now - (1 << i) >= y) now -= (1 << i), ans = 0;
		else ans = 1;
	}
	return ans;
}
int n, k, ans[maxn], a[maxn];
int main()
{
	n = read(), k = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n)
	{
		int tot = 0;
		ru(j, i, min(i + 20, n))
		{
			if(tot >= 20) break;
			if((ll)a[i] * (1 << tot) >= (1 << 20)) break;
			int A = n - 1 - (j - i + 2), B = k - 2;
			if(i == 1) A++, B++;
			if(j == n) A++, B++;
//			printf("%d %d %d %d %d\n", i, j, A, B, calc(A, B));
			ans[a[i] * (1 << tot)] ^= calc(A, B);
			tot += a[j + 1];
		}
	}
	int fl = 0;
	rd(i, (1 << 20) - 1, 0)
	{
		if(ans[i]) fl = 1;
		if(fl) printf("%d", ans[i]);
	}
	if(!fl) printf("0");
	return 0;
}