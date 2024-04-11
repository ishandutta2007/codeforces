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
#define mid ((l + r) >> 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int main()
{
	int n = read();
	int x = (n * 2 + 1) / 3; printf("%d\n", x);
	int fl = 0; if(x % 2 == 0) fl = 1, x--;
	int a = x / 2, b = x - a;
	for (int i = 1; i <= a; i++) printf("%d %d\n", i, a - i + 1);
	for (int i = 1; i <= b; i++) printf("%d %d\n", a + i, a + b - i + 1);
	if(fl) printf("%d %d\n", a + b + 1, a + b + 1);
	return 0;
}