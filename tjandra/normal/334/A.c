#include<stdio.h>
typedef unsigned u;
int main()
{
	u n,k,i,j,N;
	scanf("%u",&n);N=n*n;
	for(i=0;i++<n;)
	{
		for(j=i;j<=N;j+=n<<1)
		{
			printf("%u %u ",j,j+(n<<1)-(i<<1)+1);
		}
		putchar('\n');
	}
	return 0;
}