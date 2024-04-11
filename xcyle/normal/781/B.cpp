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
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, vis2[maxn];
int vis[30][30][30];
char s1[maxn][30], s2[maxn][30];
char ans[maxn][5];
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%s", s1[i] + 1, s2[i] + 1);
		vis[s1[i][1] - 'A'][s1[i][2] - 'A'][s1[i][3] - 'A']++;
		for (int j = 1; j <= 3; j++) ans[i][j] = s1[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(!vis2[j] && vis[s1[i][1] - 'A'][s1[i][2] - 'A'][s1[i][3] - 'A'] > 1)
			{
				vis2[j] = 1;
				ans[j][3] = s2[j][1], vis[s1[j][1] - 'A'][s1[j][2] - 'A'][s2[j][1] - 'A']++;
			}
		}
	}
	int fl = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int t = 1;
			for (int k = 1; k <= 3; k++) t &= (ans[i][k] == ans[j][k]);
			fl |= t;
		}
	}
	if(fl) printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i = 1; i <= n; i++) 
		{for (int j = 1; j <= 3; j++) printf("%c", ans[i][j]); printf("\n");}
	}
	return 0;
}