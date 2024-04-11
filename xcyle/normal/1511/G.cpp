/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, q, sum[maxn], st[maxn][22];
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) sum[read()]++;
	for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
	for (int i = m; i >= 1; i--)
	{
		st[i][0] = 0;
		for (int j = 1; j <= 20; j++)
		{
			if(i + (1 << j) > m) break;
			st[i][j] = st[i][j - 1] ^ st[i + (1 << (j - 1))][j - 1];
			if((sum[i + (1 << j) - 1] - sum[i + (1 << (j - 1)) - 1]) & 1) st[i][j] ^= (1 << (j - 1));
		}
	}
	q = read();
	for (int i = 1; i <= q; i++)
	{
		int l = read(), r = read(), ans = 0;
		for (int j = 20; j >= 0; j--)
		{
			if(l + (1 << j) > r) continue;
			ans ^= st[l][j], l += (1 << j);
			if((sum[r] - sum[l - 1]) & 1) ans ^= (1 << j);
		}
		ans ? printf("A") : printf("B");
	}
	return 0;
}