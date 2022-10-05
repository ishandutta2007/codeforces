#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
int main()
{
	int i,n;
	scanf("%d",&n);
	for (i=2;i<=n+1;i++)
		if (i==2)
			printf("2\n");
		else
			printf("%I64d\n",(long long)i*i*(i-1)-i+2);
	return 0;
}