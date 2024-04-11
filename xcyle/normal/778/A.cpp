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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char s[maxn], t[maxn];
int rk[maxn], pos[maxn], lenp, lent;
bool check(int x)
{
	int now = 1;
	for (int i = 1; i <= lent; i++)
	{
		while((s[now] != t[i] || rk[now] <= x) && now <= lenp) now++;
		if(now > lenp) return 0;
		now++;
	}
	return 1;
}
int main()
{
	scanf("%s%s", s + 1, t + 1);
	lenp = strlen(s + 1), lent = strlen(t + 1);
	for (int i = 1; i <= lenp; i++) 
	{
		scanf("%d", &pos[i]);
		rk[pos[i]] = i;
	}
	int l = 0, r = lenp, mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
	return 0;
}