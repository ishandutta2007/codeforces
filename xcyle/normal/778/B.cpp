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
#define maxn 5005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
map<int, int> p;
int n, m, f[maxn][1005][2];
char a[maxn], b[maxn], c[maxn];
int l[1005][2], r[1005][2];
int res[1005][2];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%s%s", a, b, c);
		int llen = strlen(a), tmp = 0;
		for (int j = 0; j < llen; j++)
		{
			tmp = ((ll)tmp * 100017 % mo + a[j] - 'a') % mo;
		}
		p.insert(make_pair(tmp, i));
		if(c[0] == '1' || c[0] == '0')
		{
			for (int j = 1; j <= m; j++)
			{
				f[i][j][0] = f[i][j][1] = c[j - 1] - '0';
			}
		}
		else
		{
			scanf("%s%s", a, b);
			if(c[0] == '?') 
			{
				for (int j = 1; j <= m; j++)
				{
					l[j][0] = 0, l[j][1] = 1;
				}
			}
			else
			{
				int len = strlen(c), tmp = 0;
				for (int j = 0; j < len; j++)
				{
					tmp = ((ll)tmp * 100017 % mo + c[j] - 'a') % mo;
				}
				map<int, int>::iterator it = p.find(tmp);
				for (int j = 1; j <= m; j++)
				{
					l[j][0] = f[it->second][j][0], l[j][1] = f[it->second][j][1];
				}
			}
			if(b[0] == '?')
			{
				for (int j = 1; j <= m; j++)
				{
					r[j][0] = 0, r[j][1] = 1;
				}
			}
			else
			{
				int len = strlen(b), tmp = 0;
				for (int j = 0; j < len; j++)
				{
					tmp = ((ll)tmp * 100017 % mo + b[j] - 'a') % mo;
				}
				map<int, int>::iterator it = p.find(tmp);
				for (int j = 1; j <= m; j++)
				{
					r[j][0] = f[it->second][j][0], r[j][1] = f[it->second][j][1];
				}
//				printf("!!%d\n", (it->second));
			}
			for (int j = 1; j <= m; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					if(a[0] == 'X') f[i][j][k] = (l[j][k] ^ r[j][k]);
					if(a[0] == 'O') f[i][j][k] = (l[j][k] | r[j][k]);
					if(a[0] == 'A') f[i][j][k] = (l[j][k] & r[j][k]);
				}
			}
		}
//		for (int j = 1; j <= m; j++)
//		{
//			printf("%d", f[i][j][0]);
//		}
//		printf("\n");
//		for (int j = 1; j <= m; j++)
//		{
//			printf("%d", f[i][j][1]);
//		}
//		printf("\n");
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				res[j][k] += f[i][j][k];
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if(res[i][0] <= res[i][1]) printf("0");
		else printf("1");
	}
	printf("\n");
	for (int i = 1; i <= m; i++)
	{
		if(res[i][0] >= res[i][1]) printf("0");
		else printf("1");
	}
	return 0;
}