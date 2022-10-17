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
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int vis[maxn], n;
int main()
{
	scanf("%d", &n);
	if(n <= 3)
	{
		printf("0\n");
		return 0; 
	} 
	int mx = 0, x = 0;
	for (int i = 1; i <= n; i++)
	{
		if(n - (n + i - 1) / i - (i - 1) > mx)
		{
			mx = n - (n + i - 1) / i - (i - 1);
			x = i;
		}
	}
	int now = 0;
	for (int i = 1; i <= 10000; i++)
	{
		vector<int> ans;
		ans.clear();
		for (int j = 1; j <= n; j++)
		{
			if(j % x == 0 || j == n) continue;
			if(!vis[j])
			{
				ans.push_back(j);
				vis[j] = 1;
			}
		}
		printf("%d\n", ans.size());
		for (int j = 0; j < ans.size(); j++) printf("%d ", ans[j]);
		printf("\n");
		fflush(stdout);
		int pos;
		scanf("%d", &pos);
		for (int j = 0; j < ans.size(); j++) vis[(pos + j - 1) % n + 1] = 0;
	}
	printf("0\n");
	return 0;
}