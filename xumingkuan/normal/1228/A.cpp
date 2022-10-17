#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int l, r;
	scanf("%d%d", &l, &r);
	int dig[10];
	for(int i = l; i <= r; i++)
	{
		int x = i;
		int cnt = 0;
		while(x > 0)
		{
			dig[cnt++] = x % 10;
			x /= 10;
		}
		bool ok = true;
		for(int j = 0; j < cnt && ok; j++)
			for(int k = 0; k < j; k++)
				if(dig[j] == dig[k])
				{
					ok = false;
					break;
				}
		if(ok)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}