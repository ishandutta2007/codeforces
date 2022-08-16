#include<stdio.h>
typedef unsigned u;
int main()
{
	u n,k,N,i,d;
	scanf("%u%u",&n,&k);
	N=n<<1;
	if(k==0)
	{
		printf("%u",i=N);
		while(--i)printf(" %u",i);
		putchar('\n');
		return 0;
	}
	printf("1 %u",k+1);
	for(i=N;i>1;i--)
	{
		if(i==k+1)continue;
		printf(" %u",i);
	}
	putchar('\n');
	return 0;
}