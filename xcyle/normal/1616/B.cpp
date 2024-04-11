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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
char s[maxn];
void solve()
{
	scanf("%d%s", &n, s + 1);
	int pos = n;
	int las = 0;
	if(s[1] == s[2])
	{
		pos = 1;
	}
	else
	{
	for (int i = 1; i < n; i++)
	{
		if(s[i] - 'a' < s[i + 1] - 'a')
		{
			pos = i;
			break;
		}
	}
	}
	for (int i = 1; i <= pos; i++) printf("%c", s[i]);
	for (int i = pos; i >= 1; i--) printf("%c", s[i]);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}