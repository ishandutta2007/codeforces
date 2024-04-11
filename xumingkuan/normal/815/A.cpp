#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int oo = 1010101010;
int n, m, mn = oo, mn1 = oo, ans = oo, ansp = -1;
int a[123][123], b[123], c[123];
int test(int st, bool type = false)
{
	b[1] = st;
	int ret = 0;
	for(int i = 1; i <= m; i++)
	{
		ret += (c[i] = a[1][i] - st);
		if(c[i] < 0)
			return oo;
		if(type)
			for(int k = 1; k <= c[i]; k++)
				printf("col %d\n", i);
	}
	for(int i = 1; i <= n; i++)
	{
		ret += (b[i] = a[i][1] - c[1]);
		if(b[i] < 0)
			return oo;
		if(type)
			for(int k = 1; k <= b[i]; k++)
				printf("row %d\n", i);
		for(int j = 1; j <= m; j++)
			if(b[i] + c[j] != a[i][j])
				return oo;
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] < mn)
				mn = a[i][j];
			if(i == 1 && a[i][j] < mn1)
				mn1 = a[i][j];
		}
//	mn1 -= mn;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++)
//			a[i][j] -= mn;
	for(int i = 0; i <= a[1][1]; i++)
	{
		int now = test(i);
		if(now < ans)
			ans = now, ansp = i;
	}
	if(ansp == -1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);
//	printf("%d\n", ans + mn * min(n, m));
//	for(int i = 1; i <= mn; i++)
//	{
//		if(n < m)
//		{
//			for(int j = 1; j <= n; j++)
//				printf("row %d\n", j);
//		}
//		else
//		{
//			for(int j = 1; j <= m; j++)
//				printf("col %d\n", j);
//		}
//	}
	test(ansp, true);
	return 0;
}