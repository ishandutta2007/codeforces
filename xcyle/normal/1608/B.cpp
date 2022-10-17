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
int t, n, a, b;
void solve()
{
	scanf("%d%d%d", &n, &a, &b);
	if(a - b > 1 || b - a > 1 || a + b > n - 2)
	{
		printf("-1\n");
		return;
	}
	int l = 1, r = n;
	if(a == b)
	{
		printf("1 ");
		l++;
		for (int i = 1; i <= a; i++)
		{
			printf("%d ", r--);
			printf("%d ", l++);
		}
		for (int i = l; i <= r; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	else if(a == b + 1)
	{
		printf("1 ");
		l++;
		for (int i = 1; i <= a; i++)
		{
			printf("%d ", r--);
			if(i != a) printf("%d ", l++);
		}
		for (int i = r; i >= l; i--)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	else
	{
		printf("%d ", n);
		r--;
		for (int i = 1; i <= b; i++)
		{
			printf("%d ", l++);
			if(i != b) printf("%d ", r--);
		}
		for (int i = l; i <= r; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d", &t);
	while(t--) solve(); 
	return 0;
}