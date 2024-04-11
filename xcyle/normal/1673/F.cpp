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
int n, k, id[32];
int main()
{
	ru(i, 0, 31) 
	{
		ru(j, 0, 4) if((i >> j) & 1) id[i] |= (1 << (2 * j));
	}
	for (int i = 1; i <= 16; i *= 2)
	{
		for (int j = i; j < 32; j += i * 2)
		{
			ru(k, j, j + i / 2 - 1) swap(id[k], id[j + i - 1 - (k - j)]); 
		}
	}
	n = read(), k = read();
	ru(i, 1, n)
	{
		ru(j, 1, n - 1) printf("%d ", (id[j] ^ id[j - 1]));
		printf("\n");
	}
	ru(i, 1, n - 1)
	{
		ru(j, 1, n) printf("%d ", (id[i] ^ id[i - 1]) * 2);
		printf("\n");
	}
	fflush(stdout);
	int now = 0;
	while(k--)
	{
		now ^= read();
		ru(i, 0, n - 1) ru(j, 0, n - 1)
		{
			if(id[i] * 2 + id[j] == now) printf("%d %d\n", i + 1, j + 1);
		} 
		fflush(stdout);
	}
	return 0;
}