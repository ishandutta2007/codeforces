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
int f[10][2];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) f[i][0] = 0, f[i][1] = 1;
	while(n--)
	{
		char s[2];
		int x;
		scanf("%s%d", s, &x);
		for (int j = 0; j < 10; j++)
		{
			int k = ((x >> j) & 1);
			if(s[0] == '|')
			{
				f[j][0] = (f[j][0] | k);
				f[j][1] = (f[j][1] | k);
			} 
			if(s[0] == '^')
			{
				f[j][0] = (f[j][0] ^ k);
				f[j][1] = (f[j][1] ^ k);
			} 
			if(s[0] == '&')
			{
				f[j][0] = (f[j][0] & k);
				f[j][1] = (f[j][1] & k);
			} 
		}
	}
	int x1 = 0, x2 = 0, x3 = 0;
	for (int i = 0; i < 10; i++)
	{
		if(!f[i][0] && f[i][1]) x1 ^= (1 << i);
		if(f[i][0] && !f[i][1]) x1 ^= (1 << i), x2 ^= (1 << i);
		if(f[i][1] && f[i][0]) x3 ^= (1 << i);
	} 
	printf("3\n");
	printf("& %d\n^ %d\n| %d\n", x1, x2, x3);
	return 0;
}