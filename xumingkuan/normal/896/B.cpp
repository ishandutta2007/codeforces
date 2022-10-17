#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c, a[1010], mx = 0, mn;
int main()
{
	scanf("%d%d%d", &n, &m, &c);
	a[0] = -1;
	mn = n + 1;
	a[n + 1] = c + 1;
	for(int i = 1; i <= m; i++)
	{
		int p;
		scanf("%d", &p);
		if(p <= c / 2)
		{
			bool flag = false;
			if(a[mx] <= p)
			{
				a[++mx] = p;
				printf("%d\n", mx);
				fflush(stdout);
				if(mx == mn - 1)
					return 0;
				flag = true;
			}
			if(flag)
				continue;
			for(int j = mx - 1; j >= 0; j--)
				if(a[j] <= p)
				{
					a[j + 1] = p;
					printf("%d\n", j + 1);
					fflush(stdout);
					break;
				}
		}
		else
		{
			bool flag = false;
			if(a[mn] >= p)
			{
				a[--mn] = p;
				printf("%d\n", mn);
				fflush(stdout);
				if(mx == mn - 1)
					return 0;
				flag = true;
			}
			if(flag)
				continue;
			for(int j = mn + 1; j <= n + 1; j++)
				if(a[j] >= p)
				{
					a[j - 1] = p;
					printf("%d\n", j - 1);
					fflush(stdout);
					break;
				}
		}
	}
	return 0;
}