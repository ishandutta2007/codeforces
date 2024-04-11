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
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, cnt[100];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		int tot = 0;
		while(x % 2 == 0)
		{
			x /= 2;
			tot++;
		}
		cnt[tot]++;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * 2 % mo;
	ans = (ans + mo - 1) % mo; 
	int sum = 1;
	for (int i = 99; i >= 1; i--)
	{
		if(!cnt[i]) continue;
		int tmp = 1;
		for (int j = 1; j < cnt[i]; j++) tmp = tmp * 2 % mo;
		ans = (ans + mo - (ll)tmp * sum % mo) % mo;
		sum = (ll)sum * tmp % mo * 2 % mo;
	}
	printf("%d\n", ans);
	return 0;
}