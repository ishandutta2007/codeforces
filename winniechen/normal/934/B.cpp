#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n>36)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		while(n)
		{
			if(n<2)
			{
				printf("4");return 0;
			}else
			{
				printf("8");n-=2;	
			}
		}
		puts("");
	}
	return 0;
}