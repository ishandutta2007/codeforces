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
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, l, r, cnt[30];
void work(int x)
{
	for (int i = 20; i >= 0; i--)
	{
		if((x >> i) & 1)
		{
			cnt[i] += (1 << i);
			for (int j = i - 1; j >= 0; j--)
			{
				cnt[j] += (1 << (i - 1));
			}
		}
		else
		{
			cnt[i] += (x & ((1 << i) - 1)) + 1;
		}
	}
}
void solve()
{
	scanf("%d%d", &l, &r);
	for (int i = 0; i <= 20; i++) cnt[i] = 0;
	work(l - 1);
	for (int i = 0; i <= 20; i++) cnt[i] = -cnt[i];
	work(r);
	int ans = r - l;
	for (int i = 0; i <= 20; i++) ans = min(ans, cnt[i]);
	printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}