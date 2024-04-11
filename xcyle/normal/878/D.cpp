/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#include <bitset>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, q, a[15][maxn];
bitset<5005> f[maxn];
int main()
{
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < (1 << k); j++)
		{
			f[i][j] = ((j >> (i - 1)) & 1);
		}
	}
	int cnt = k;
	while(q--)
	{
		int tp, x, y;
		scanf("%d%d%d", &tp, &x, &y);
		if(tp == 1 || tp == 2) cnt++;
		if(tp == 1) f[cnt] = (f[x] | f[y]);
		if(tp == 2) f[cnt] = (f[x] & f[y]);
		if(tp == 3)
		{
			int l = 1, r = 1000000000, mid;
			while(l < r)
			{
				mid = (l + r + 1) >> 1;
				int tmp = 0;
				for (int j = 1; j <= k; j++)
				{
					if(a[j][y] >= mid) tmp ^= (1 << (j - 1));
				}
				if(f[x][tmp]) l = mid;
				else r = mid - 1;
			}
			printf("%d\n", l);
		}
	}
	return 0;
}