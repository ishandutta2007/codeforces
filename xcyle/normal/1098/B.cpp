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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char hoho[4] = {'A', 'C', 'G', 'T'};
int n, m;
char tmp[maxn];
vector<char> s[maxn];
int cnt[2][maxn][2][4];
int tp, tt[2][2], res;
int tpp, t[2][2];
vector<char> ans[maxn];
void check(int tpp)
{
	if(!tpp)
	{
		int val = 0;
		for (int i = 1; i <= n; i++)
		{
			val += max(cnt[0][i][0][t[i & 1][0]] + cnt[0][i][1][t[i & 1][1]], cnt[0][i][1][t[i & 1][0]] + cnt[0][i][0][t[i & 1][1]]);
		}
		if(val >= res)
		{
			res = val;
			tp = 0;
			for (int i = 0; i < 4; i++) tt[(i & 2) >> 1][i & 1] = t[(i & 2) >> 1][i & 1];
		}
	}
	else
	{
		int val = 0;
		for (int i = 1; i <= m; i++)
		{
			val += max(cnt[1][i][0][t[i & 1][0]] + cnt[1][i][1][t[i & 1][1]], cnt[1][i][1][t[i & 1][0]] + cnt[1][i][0][t[i & 1][1]]);
		}
		if(val >= res)
		{
			res = val;
			tp = 1;
			for (int i = 0; i < 4; i++) tt[(i & 2) >> 1][i & 1] = t[(i & 2) >> 1][i & 1];
		}
	}
}
void out()
{
	if(!tpp)
	{
		int val = 0;
		for (int i = 1; i <= n; i++)
		{
			int p = cnt[0][i][0][t[i & 1][0]] + cnt[0][i][1][t[i & 1][1]] <= cnt[0][i][1][t[i & 1][0]] + cnt[0][i][0][t[i & 1][1]];
			for (int j = 1; j <= m; j++)
			{
				ans[i].push_back(hoho[t[i & 1][(j & 1) ^ p]]);
			}
		}
	}
	else
	{
		int val = 0;
		for (int i = 1; i <= m; i++)
		{
			int p = cnt[1][i][0][t[i & 1][0]] + cnt[1][i][1][t[i & 1][1]] <= cnt[1][i][1][t[i & 1][0]] + cnt[1][i][0][t[i & 1][1]];
			for (int j = 1; j <= n; j++)
			{
				ans[j].push_back(hoho[t[i & 1][(j & 1) ^ p]]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) putchar(ans[i][j]);
		putchar('\n');
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		s[i].push_back('0');
		ans[i].push_back('0');
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", tmp + 1);
		for (int j = 1; j <= m; j++) s[i].push_back(tmp[j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(s[i][j] == 'A') cnt[0][i][j & 1][0]++, cnt[1][j][i & 1][0]++;
			if(s[i][j] == 'C') cnt[0][i][j & 1][1]++, cnt[1][j][i & 1][1]++;
			if(s[i][j] == 'G') cnt[0][i][j & 1][2]++, cnt[1][j][i & 1][2]++;
			if(s[i][j] == 'T') cnt[0][i][j & 1][3]++, cnt[1][j][i & 1][3]++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if(i == j || j == k || i == k) continue;
				t[0][0] = i, t[0][1] = j, t[1][0] = k, t[1][1] = (i ^ j ^ k);
				check(0), check(1);
			}
		}
	}
	tpp = tp;
	for (int i = 0; i < 4; i++) t[(i & 2) >> 1][i & 1] = tt[(i & 2) >> 1][i & 1];
	out();
	return 0;
}