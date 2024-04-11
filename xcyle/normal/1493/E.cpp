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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
char l[maxn], r[maxn];
int main()
{
	scanf("%d%s%s", &n, l + 1, r + 1);
	if(l[1] != r[1])
	{
		for (int i = 1; i <= n; i++) printf("1");
		return 0;
	}
	int fl = 1;
	for (int i = 1; i <= n; i++) fl &= l[i] == r[i];
	fl |= r[n] == '1';
	if(fl)
	{
		for (int i = 1; i <= n; i++) printf("%c", r[i]);
		return 0;
	}
	for (int i = n; i >= 1; i--)
	{
		if(l[i] == '1') l[i] = '0';
		else
		{
			l[i] = '1';
			break;
		}
	}
	fl = 1;
	for (int i = 1; i <= n; i++) fl &= l[i] == r[i];
	if(fl)
	{
		for (int i = 1; i <= n; i++) printf("%c", r[i]);
		return 0;
	}
	for (int i = 1; i < n; i++) printf("%c", r[i]);
	printf("1");
	return 0;
}