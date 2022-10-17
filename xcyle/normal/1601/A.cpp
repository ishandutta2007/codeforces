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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[200005], cnt[40];
vector<int> ans;
void solve()
{
	scanf("%d", &n);
	for (int j = 0; j < 30; j++) cnt[j] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = 0; j < 30; j++) cnt[j] += ((a[i] >> j) & 1);
	}
	ans.clear();
	for (int i = 1; i <= n; i++)
	{
		int flag = 1;
		for (int j = 0; j < 30; j++)
		{
			if(cnt[j] % i != 0) flag = 0; 
		}
		if(flag) ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}