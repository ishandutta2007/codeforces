#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, a[303030];
long long c[2] = {0, 0};
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		c[0] += a[i] / 2;
		c[1] += a[i] / 2;
		if(a[i] % 2 == 1)
			c[i % 2]++;
	}
	printf("%I64d\n", min(c[0], c[1]));
	return 0;
}