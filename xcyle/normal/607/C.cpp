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
const int mo = 998244353;
const int bas = 100097;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
char a[maxn], b[maxn];
char s[4][maxn];
int HASH[4][maxn];
char change(char c)
{
	if(c == 'N') return 'S';
	if(c == 'S') return 'N';
	if(c == 'E') return 'W';
	if(c == 'W') return 'E'; 
}
int pw[maxn];
void work(int tp)
{
	HASH[tp][0] = 0;
	for (int i = 1; i <= n; i++) HASH[tp][i] = ((ll)HASH[tp][i - 1] * bas % mo + s[tp][i] - 'A') % mo;
}
int check(int tp, int l, int r)
{
	return (HASH[tp][r] - (ll)HASH[tp][l - 1] * pw[r - l + 1] % mo + mo) % mo;
}
int main()
{
	scanf("%d%s%s", &n, a + 1, b + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = (ll)pw[i - 1] * bas % mo;
	n--;
	for (int i = 1; i <= n; i++)
	{
		s[0][n - i + 1] = change(a[i]);
		s[1][n - i + 1] = change(b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		s[2][i] = a[i];
		s[3][i] = b[i];
	}
	for (int i = 0; i < 4; i++) work(i);
	for (int i = 0; i < n; i++)
	{
		if(check(2, i + 1, n) == check(1, 1, n - i) && check(0, 1, n - i) == check(3, i + 1, n))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}