#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int a,b,r;
int main()
{
	scanf("%d%d%d",&a,&b,&r);
	if(a>=2*r&&b>=2*r)
	{
		printf("First");
	}
	else
	{
		printf("Second");
	}
	return 0;
}
//dd