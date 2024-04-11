#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a>b+c)
	{
		printf("+");
		return 0;
	}
	if(b>a+c)
	{
		printf("-");
		return 0;
	}
	if(a==b&&!c)
	{
		printf("0");
		return 0;
	}
	printf("?");
	return 0;
}//