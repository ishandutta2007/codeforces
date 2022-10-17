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
int n, k;
void solve()
{
	n = read(), k = read();
	if(k == 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			printf("%d %d\n", i, n - 1 - i);
		}
	}
	else if(k != n - 1)
	{
		printf("%d %d\n", k, n - 1);
		printf("0 %d\n", n - 1 - k);
		for (int i = 1; i < n / 2; i++)
		{
			if(i != k && i != n - 1 - k)
			{
				printf("%d %d\n", i, n - 1 - i);
			}
		}
	}
	else
	{
		if(n == 4)
		{
			printf("-1\n");
			return;
		}
		printf("%d %d\n", 0, n / 2 - 2);
		printf("%d %d\n", n / 2 - 1, n - 1);
		printf("%d %d\n", n / 2, n / 2 + 1);
		for (int i = 1; i < n / 2; i++)
		{
			if(i != n / 2 - 2 && i != n / 2 - 1)
			{
				printf("%d %d\n", i, n - 1 - i);
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}