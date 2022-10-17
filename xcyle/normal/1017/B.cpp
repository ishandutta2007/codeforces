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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
long long n;
char a[maxn], b[maxn];
int main()
{
	scanf("%lld", &n);
	scanf("%s%s", a + 1, b + 1);
	long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i++)
	{
		if(a[i] == '1') cnt3++;
		if(a[i] == '1' && b[i] == '1') cnt1++;
		if(a[i] == '0' && b[i] == '1') cnt2++;
	}
	long long ans = n * (n - 1) / 2 - cnt3 * (cnt3 - 1) / 2 - ((n - cnt3) * (n - cnt3 - 1)) / 2 - cnt1 * cnt2;
	printf("%lld", ans);
	return 0;
}