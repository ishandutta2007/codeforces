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
int n;
int main()
{
	scanf("%d", &n);
	if(n % 4 == 2 || n % 4 == 3)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n == 1) return 0;
	for (int i = 2; i <= n - 2; i++)
	{
		for (int j = 1; j < i; j++) printf("%d %d\n", j, i);
	}
	if(n % 4 == 1)
	{
		printf("%d %d\n", (n - 1) / 2, n - 1);
	}
	for (int i = 1; i <= (n - 2) / 2; i++)
	{
		printf("%d %d\n", i, n - 1);
		printf("%d %d\n", n - 1 - i, n);
		printf("%d %d\n", i, n);
		printf("%d %d\n", n - 1 - i, n - 1);
	}
	if(n % 4 == 1)
	{
		printf("%d %d\n", (n - 1) / 2, n);
	}
	printf("%d %d\n", n - 1, n);
	return 0;
}