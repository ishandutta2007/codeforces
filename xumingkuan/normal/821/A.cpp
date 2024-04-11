#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[55][55], n;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] == 1)
				continue;
			bool flag = false;
			for(int s = 1; s <= n && !flag; s++)
				for(int t = 1; t <= n && !flag; t++)
					if(a[i][j] == a[i][s] + a[t][j])
						flag = true;
			if(!flag)
			{
				puts("No");
				return 0;
			}
		}
	puts("Yes");
	return 0;
}