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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, buc[maxn];
char s[maxn];
void solve()
{
	n = read(), m = read();
	scanf("%s", s + 1);
	int all = 0; for (int i = 1; i <= n; i++) all += s[i] - '0';
	if((ll)all * m % n != 0)
	{
		printf("-1\n");
		return;
	}
	int cnt = (ll)all * m / n;
	for (int i = 1; i <= n; i++) buc[i] = buc[i - 1] + s[i] - '0';
	for (int i = 1; i + m - 1 <= n; i++)
	{
		if(buc[i + m - 1] - buc[i - 1] == cnt)
		{
			printf("1\n%d %d\n", i, i + m - 1);
			return;
		}
	}
	m = n - m, cnt = all - cnt;
	for (int i = 1; i + m - 1 <= n; i++)
	{
		if(buc[i + m - 1] - buc[i - 1] == cnt)
		{
			printf("2\n%d %d\n%d %d\n", 1, i - 1, i + m, n);
			return;
		}
	}
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}