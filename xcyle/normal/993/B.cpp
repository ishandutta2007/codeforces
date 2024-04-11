#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1005
using namespace std;
int n, m, a[2][maxn], b[2][maxn];
int check(int x, int y)
{
	if(a[0][x] == b[0][y] && a[1][x] != b[1][y]) return a[0][x];
	if(a[0][x] == b[1][y] && a[1][x] != b[0][y]) return a[0][x];
	if(a[1][x] == b[0][y] && a[0][x] != b[1][y]) return a[1][x];
	if(a[1][x] == b[1][y] && a[0][x] != b[0][y]) return a[1][x];
	return 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[0][i], &a[1][i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &b[0][i], &b[1][i]);
	}
	int flag0 = 1, flag1 = 1, flag2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int t[20], cnt = 0;
		memset(t, 0, sizeof(t));
		for (int j = 1; j <= m; j++)
		{
			if(check(i, j) && !t[check(i, j)]) 
			{
				t[check(i, j)] = 1; 
				cnt++;
			}
		}
		if(cnt > 1)
		{
			flag0 = 0;
		}
		
	}
	for (int i = 1; i <= m; i++)
	{
		int t[20], cnt = 0;
		memset(t, 0, sizeof(t));
		for (int j = 1; j <= n; j++)
		{
			if(check(j, i) && !t[check(j, i)]) 
			{
				t[check(j, i)] = 1; 
				cnt++;
			}
		}
		if(cnt > 1)
		{
			flag1 = 0;
		}
	}
	int t[20], cnt = 0;
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(check(j, i) && !t[check(j, i)]) 
			{
				flag2 = check(j, i);
				t[check(j, i)] = 1; 
				cnt++;
			}
		}
	}
	if(cnt > 1 || cnt == 0)
	{
		flag2 = 0;
	}
	if(flag2) printf("%d", flag2);
	else if(flag1 && flag0) printf("0");
	else printf("-1");
	return 0;
}