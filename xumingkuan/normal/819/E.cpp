#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans[101010][5], cnt = 0;
inline void add3(int x, int y, int z)
{
	cnt++;
	ans[cnt][0] = 3;
	ans[cnt][1] = x;
	ans[cnt][2] = y;
	ans[cnt][3] = z;
}
inline void add4(int x, int y, int z, int w)
{
	cnt++;
	ans[cnt][0] = 4;
	ans[cnt][1] = x;
	ans[cnt][2] = y;
	ans[cnt][3] = z;
	ans[cnt][4] = w;
}
bool solve(int n)
{
	if(n == 3)
	{
		add3(1, 2, 3);
		add3(1, 2, 3);
		return true;
	}
	if(n == 4)
	{
		add3(1, 2, 3);
		add3(1, 2, 4);
		add3(1, 3, 4);
		add3(2, 3, 4);
		return true;
	}
	if(n == 5)
	{
		add4(4, 1, 5, 2);
		add4(4, 2, 5, 3);
		add3(4, 5, 1);
		add3(4, 5, 3);
		return solve(3);
	}
	if(n % 2 == 1)
	{
		for(int i = 1; i <= n - 3; i += 2)
		{
			add4(n - 2, i, n - 1, i + 1);
			add4(n - 1, i, n, i + 1);
			add4(n, i, n - 2, i + 1);
		}
		add3(n, n - 1, n - 2);
		add3(n, n - 1, n - 2);
		return solve(n - 3);
	}
	else
	{
		for(int i = 1; i <= n - 4; i += 2)
		{
			add4(n - 1, i, n, i + 1);
			add4(n - 1, i, n, i + 1);
		}
		add4(n - 1, n - 3, n, n - 2);
		add3(n, n - 1, n - 2);
		add3(n, n - 1, n - 3);
		return solve(n - 2);
	}
}
int main()
{
	scanf("%d", &n);
	if(solve(n))
	{
		printf("%d\n", cnt);
		for(int i = 1; i <= cnt; i++)
		{
			printf("%d", ans[i][0]);
			for(int j = 1; j <= ans[i][0]; j++)
				printf(" %d", ans[i][j]);
			printf("\n");
		}
	}
	else
		puts("-1");
	return 0;
}