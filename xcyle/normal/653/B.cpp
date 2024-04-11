/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

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
int n, k, ans;
char s[50][2], t[50][2];
char now;
void dfs(int step)
{
	if(step == n)
	{
		ans++;
		return;
	}
	char tmp = now;
	for (int i = 1; i <= k; i++)
	{
		if(t[i][0] == now)
		{
			now = s[i][0];
			dfs(step + 1);
			now = tmp;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%s%s", s[i], t[i]);
	}
	now = 'a';
	dfs(1);
	printf("%d\n", ans);
	return 0;
}