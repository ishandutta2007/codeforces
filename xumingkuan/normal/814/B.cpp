#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[10101], b[10101], c[10101], visit[10101], vn = 0;
int main()
{
	memset(visit, 0, sizeof(visit));
	memset(c, 0, sizeof(c));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == b[i] && !visit[a[i]])
			visit[a[i]] = 1, vn++, c[i] = a[i];
	}
	if(vn == n - 1)
	{
		int tmp = 0, tmp2 = 0;
		for(int i = 1; i <= n; i++)
			if(c[i] == 0)
				tmp = i;
		for(int i = 1; i <= n; i++)
			if(visit[i] == 0)
				tmp2 = i;
		c[tmp] = tmp2;
	}
	else
	{
		int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
		for(int i = 1; i <= n; i++)
			if(c[i] == 0)
				(tmp1 ? tmp2 : tmp1) = i;
		for(int i = 1; i <= n; i++)
			if(visit[i] == 0)
				(tmp3 ? tmp4 : tmp3) = i;
		if((a[tmp1] == tmp3) + (a[tmp2] == tmp4) == 1 && (b[tmp1] == tmp3) + (b[tmp2] == tmp4) == 1)
			c[tmp1] = tmp3, c[tmp2] = tmp4;
		else
			c[tmp1] = tmp4, c[tmp2] = tmp3;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", c[i]);
	return 0;
}