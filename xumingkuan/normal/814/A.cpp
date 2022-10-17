#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int a[1010];
int main()
{
	scanf("%d%d", &n, &k);
	if(k >= 2)
	{
		printf("Yes\n");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	for(int i = 1; i <= n; i++)
		if(a[i] == 0)
			a[i] = k;
	for(int i = 2; i <= n; i++)
		if(a[i] < a[i - 1])
		{
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}