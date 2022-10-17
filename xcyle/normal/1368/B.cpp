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
long long n;
int a[12];
char s[11] = {',', 'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
int main()
{
	scanf("%lld", &n);
	long long now = 1;
	for (int i = 1; i <= 10; i++) a[i] = 1;
	int x = 1;
	while(1)
	{
		if(now >= n) break;
		now /= a[x];
		now *= (a[x] + 1);
		a[x]++;
		x++;
		if(x > 10) x = 1;
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			printf("%c", s[i]);
		}
	}
	return 0;
}