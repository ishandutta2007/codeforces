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
int n, k, l, r;
ll ans = 0;
vector<int> t[maxn];
void calc(int a, int b)
{
	if(l <= r) ans++;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		int x = read();
		t[x].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!t[i].size()) ans++;
	}
	for (int i = 1; i <= n; i++)
	{
		if(!t[i].size()) r = k;
		else r = t[i][0] - 1;
		if(i - 1 != 0)
		{
			if(!t[i - 1].size()) l = 0;
			else l = t[i - 1][t[i - 1].size() - 1];
			calc(i, i - 1);
		}
		if(i + 1 != n + 1)
		{
			if(!t[i + 1].size()) l = 0;
			else l = t[i + 1][t[i + 1].size() - 1];
			calc(i, i + 1);
		}
	}
	printf("%lld", ans);
	return 0;
}