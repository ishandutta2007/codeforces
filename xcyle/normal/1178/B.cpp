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
char s[1000005];
int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	long long cnt = 0, now = 0;
	long long ans = 0;
	for (int i = 1; i < len; i++)
	{
		if(s[i] == s[i + 1] && s[i] == 'v') cnt++;
	}
	for (int i = 2; i <= len; i++)
	{
		if(s[i] == 'o') ans += now * cnt;
		else if(s[i - 1] == 'v') 
		{
			now++;
			cnt--;
		}
	}
	printf("%lld", ans);
	return 0;
}