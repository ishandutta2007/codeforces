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
int T, n, a, cnt[50];
void solve()
{
	scanf("%d", &n);
	for (int j = 0; j <= 30; j++) cnt[j] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		for (int j = 0; j <= 30; j++) cnt[j] += ((a >> j) & 1);
	}
	for (int j = 30; j >= 0; j--)
	{
		if(cnt[j] & 1)
		{
			int x = cnt[j] / 2, y = n - cnt[j];
			x &= 1, y &= 1;
			if(!x || y) printf("WIN\n");
			else printf("LOSE\n");
			return;
		} 
	}
	printf("DRAW\n"); 
}
int main()
{
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}