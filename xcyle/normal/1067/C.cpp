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
void work(int x, int y, int nx, int ny, int dep)
{
	if(dep == 0) return;
	x += nx, y += ny;
	work(x, y, nx, ny, dep - 1);
	printf("%d %d\n", x, y);
}
int main()
{
	scanf("%d", &n);
	printf("1 1\n");
	n--;
	work(1, 1, -1, 0, n / 4);
	n -= n / 4;
	work(1, 1, 0, -1, n / 3);
	n -= n / 3;
	work(1, 1, 1, 0, n / 2);
	n -= n / 2;
	work(1, 1, 0, 1, n);
	return 0;
}