// 
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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[1005][1005];
void solve()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = read(); 
			if(i % 2 == 0 && j % 2 == 0 && (i + j) % 4 == 0) sum ^= a[i][j];
			if(i + j <= n && (i + j) % 4 == 0) sum ^= a[i][j];//, printf("%d %d\n", i, j);
		}
		for (int j = 1; j <= n; j++)
		{
			if(j <= n / 2) swap(a[i][j], a[i][n - j + 1]);
			if(i % 2 == 0 && j % 2 == 0 && (i + j) % 4 == 0) sum ^= a[i][j];
			if(i + j <= n && (i + j) % 4 == 0) sum ^= a[i][j];
		}
	}
	printf("%d\n", sum);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}