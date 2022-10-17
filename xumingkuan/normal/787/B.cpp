#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10101;
int n, m;
int visit[MAXN * 2];
int main()
{
	memset(visit, 0, sizeof(visit));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int k;
		scanf("%d", &k);
		int tmp;
		bool flag = true;
		for(int j = 1; j <= k; j++)
		{
			scanf("%d", &tmp);
			if(tmp < 0)
			{
				tmp = n - tmp;
				if(visit[tmp - n] == i)
					flag = false;
			}
			else
			{
				if(visit[tmp + n] == i)
					flag = false;
			}
			visit[tmp] = i;
		}
		if(flag)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}