#include <iostream>
#include <cstdio>
#define maxn 2005
using namespace std;
int n, m;
char s[maxn][maxn];
int f[maxn * maxn];
inline int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}
inline void unite(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx != fy) f[fx] = fy;
} 
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) s[0][i] = '.';
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i][0] = '.';
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if(s[i][j] == '#') f[(i - 1) * m + j] = (i - 1) * m + j;
			else x++;
		}
	}
	int flag1 = 0, flag2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= m; j++)
		{
			if(s[i][j - 1] == '.' && s[i][j] == '#') cnt++;
		}
		if(cnt > 1)
		{
			printf("-1\n");
			return 0;
		}
		if(cnt == 0) flag1 = 1;
	}
	for (int j = 1; j <= m; j++)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if(s[i - 1][j] == '.' && s[i][j] == '#') cnt++;
		}
		if(cnt > 1)
		{
			printf("-1\n");
			return 0;
		}
		if(cnt == 0) flag2 = 1;
	}
	if(flag1 ^ flag2)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if(s[i][j] == '#' && s[i][j + 1] == '#') unite((i - 1) * m + j, (i - 1) * m + j + 1);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(s[i][j] == '#' && s[i + 1][j] == '#') unite((i - 1) * m + j, i * m + j);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if(find(i) == i) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}