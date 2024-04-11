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
int n, m;
char s[55][55], t[55][55];
char a[2] = {'L', 'U'};
vector<int> ans[2];
vector<int> res[2];
void pp(int x, int y)
{
	ans[0].push_back(x);
	ans[1].push_back(y);
	if(s[x][y] == 'U')
	{
		s[x][y] = s[x + 1][y] = 'L';
		s[x][y + 1] = s[x + 1][y + 1] = 'R';
	}
	else
	{
		s[x][y] = s[x][y + 1] = 'U';
		s[x + 1][y] = s[x + 1][y + 1] = 'D';
	}
}
void work(int x, int y, int tp)
{
//	printf("%d %d\n", x, y);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			printf("%c", s[i][j]);
//		}
//		printf("\n");
//	}
	if(s[x][y] == a[tp ^ 1]) return;
	if(tp == 0) work(x + 1, y, 1);
	else work(x, y + 1, 0);
	pp(x, y);
} 
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	}
	int flag = 0;
	if(n & 1)
	{
		flag = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if(s[i][j] == 'U') t[j][i] = 'L';
				if(s[i][j] == 'D') t[j][i] = 'R';
				if(s[i][j] == 'L') t[j][i] = 'U';
				if(s[i][j] == 'R') t[j][i] = 'D';
			} 
		}
		swap(n, m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) s[i][j] = t[i][j];
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) printf("%c", s[i][j]);
//		printf("\n");
//	}
	for (int i = 1; i <= n; i += 2)
	{
		for (int j = 1; j <= m; j++)
		{
			work(i, j, 0);
		}
	}
	for (int i = 0; i < ans[0].size(); i++)
	{
		if(flag) swap(ans[0][i], ans[1][i]);
		res[0].push_back(ans[0][i]);
		res[1].push_back(ans[1][i]);
	}
	if(flag) swap(n, m);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	}
	flag = 0;
	if(n & 1)
	{
		flag = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if(s[i][j] == 'U') t[j][i] = 'L';
				if(s[i][j] == 'D') t[j][i] = 'R';
				if(s[i][j] == 'L') t[j][i] = 'U';
				if(s[i][j] == 'R') t[j][i] = 'D';
			} 
		}
		swap(n, m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) s[i][j] = t[i][j];
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) printf("%c", s[i][j]);
//		printf("\n");
//	}
	ans[0].clear(), ans[1].clear();
	for (int i = 1; i <= n; i += 2)
	{
		for (int j = 1; j <= m; j++)
		{
			work(i, j, 0);
		}
	}
	for (int i = ans[0].size() - 1; i >= 0; i--)
	{
		if(flag) swap(ans[0][i], ans[1][i]);
		res[0].push_back(ans[0][i]);
		res[1].push_back(ans[1][i]);
	}
	printf("%d\n", res[0].size());
	for (int i = 0; i < res[0].size(); i++) printf("%d %d\n", res[0][i], res[1][i]);
	return 0;
}