#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int h, w, x;
int a[1010][1010];
const int MOD = 1000000007;
int main()
{
	scanf("%d%d", &h, &w);
	memset(a, -1, sizeof(a));
	for(int i = 1; i <= h; i++)
	{
		scanf("%d", &x);
		for(int j = 1; j <= x; j++)
			a[i][j] = 1;
		a[i][x + 1] = 0;
	}
	for(int i = 1; i <= w; i++)
	{
		scanf("%d", &x);
		for(int j = 1; j <= x; j++)
		{
			if(a[j][i] == 0)
			{
				printf("0\n");
				return 0;
			}
			a[j][i] = 1;
		}
		if(a[x + 1][i] == 1)
		{
			printf("0\n");
			return 0;
		}
		a[x + 1][i] = 0;
	}
	int ans = 1;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			if(a[i][j] == -1)
				ans = (ans + ans) % MOD;
	printf("%d\n", ans);
	return 0;
}