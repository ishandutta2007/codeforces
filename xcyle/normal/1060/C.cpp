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
int n, m, a[2005], b[2005];
int mna[2005], mnb[2005];
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	int x = read();
	for (int i = 1; i <= max(n, m); i++) mna[i] = 2e9 + 1, mnb[i] = 2e9 + 1;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = i; j <= n; j++)
		{
			sum += a[j];
			mna[j - i + 1] = min(mna[j - i + 1], sum);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int sum = 0;
		for (int j = i; j <= m; j++)
		{
			sum += b[j];
			mnb[j - i + 1] = min(mnb[j - i + 1], sum);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if((ll)mna[i] * mnb[j] <= x) ans = max(ans, i * j);
		}
	}
	printf("%d\n", ans);
	return 0;
}