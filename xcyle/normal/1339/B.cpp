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
#define mid ((l + r) >> 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int a[100005], b[100005];
int main()
{
	int T = read();
	while(T--)
	{
		int n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			if(i & 1) b[i] = a[(i + 1) / 2];
			else b[i] = a[n - i / 2 + 1];
		}
		for (int i = n; i >= 1; i--) printf("%d ", b[i]);
		printf("\n");
	}
	return 0;
}