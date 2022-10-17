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
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[200005];
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int fl = 0;
	for (int i = 1; i <= n; i++) if(a[i] == 1) fl++;
	if(fl == 0 || fl == n) printf("YES\n");
	else
	{
		sort(a + 1, a + n + 1);
		for (int i = 2; i <= n; i++)
		{
			if(a[i - 1] == a[i] - 1)
			{
				printf("NO\n");
				return;
			}
		}
		printf("YES\n");
	}
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}