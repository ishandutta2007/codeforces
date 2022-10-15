#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int k;
int main()
{
	scanf("%d",&k);
	printf("2000\n");
	for(int i=1;i<=1998;i++)
	{
		printf("0 ");
	}
	int a=k,b=-k;
	k/=1999;
	printf("%d %d",a-1999*k-1999,b+k*2000+2000);
	return 0;
}