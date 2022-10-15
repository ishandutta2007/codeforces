#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n;
int main()
{
	scanf("%d",&n);
	int fu=0,zheng=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<0)
		{
			fu++;
		}
		if(x>0)
		{
			zheng++;
		}
	}
	n=(n+1)/2;
	if(fu>=n)
	{
		printf("-1");
		return 0;
	}
	if(zheng>=n)
	{
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
}