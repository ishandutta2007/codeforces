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
#define maxn 505
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn][maxn], buc[maxn * maxn], tot;
inline void modify(int col, int val)
{
	if(buc[col]) tot--;
	buc[col] += val;
	if(buc[col]) tot++;
}
int main()
{
	n = read(), k = read();
	ru(i, 1, n) ru(j, 1, n) buc[a[i][j] = read()]++;
	ru(i, 1, n * n) tot += (buc[i] != 0);
	if(tot <= k) {printf("%d\n", k - tot); return 0;}
	ru(i, 1, n)
	{
		int len = 0;
		ru(j, 1, n)
		{
			ru(k, 0, len) modify(a[i + len][j - k], -1);
			ru(k, 0, len - 1) modify(a[i + k][j], -1);
			len++;
			while(tot < k - 1 || i + len - 1 > n)
			{
				len--;
				ru(k, 0, len) modify(a[i + len][j - k], 1);
				ru(k, 0, len - 1) modify(a[i + k][j - len], 1);
			}
			//printf("%d %d %d %d\n", i, j, len, tot);
			if(tot == k || tot == k - 1) {printf("1\n"); return 0;}
			if(j == n)
			{
				while(len)
				{
					len--;
					ru(k, 0, len) modify(a[i + len][j - k], 1);
					ru(k, 0, len - 1) modify(a[i + k][j - len], 1);
				}
			}
		}
	}
	printf("2\n");
	return 0;
}