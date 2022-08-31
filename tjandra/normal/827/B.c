#include <stdio.h>
typedef unsigned u;
u A[222222],B[222222];
int main()
{
	u n,e,i,j;
	scanf("%u%u",&n,&e);
	if(n-e==1)
	{
		printf("2\n");
		for(i=1;i++<n;)printf("1 %u\n",i);
		return 0;
	}
	if(n-e==2)
	{
		printf("3\n1 2\n2 3\n");
		for(i=3;i++<n;)printf("1 %u\n",i);
		return 0;
	}
	if(n<(e<<1)+1)
	{
		printf("4\n");
		for(i=j=e;++i<n;)
		{
			printf("%u %u\n",i,n);
			printf("%u %u\n",j--,i);
		}
		while(j)
			printf("%u %u\n",j--,n);
		return 0;
	}
	printf("%u\n",(((n-1)/e)<<1)+((n-1)%e>0)+((n-1)%e>1));
	for(i=n;--i;)
	{
		if((j=i+e)>n)j=n;
		printf("%u %u\n",i,j);
	}
	return 0;
}