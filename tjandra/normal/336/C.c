#include<stdio.h>
typedef unsigned u;
u B[32],A[100000];
int main()
{
	u n,i=0,j,k,x,y;
	for(scanf("%u",&n);i<n;)
	{
		scanf("%u",&j);A[i++]=j;
		for(k=j,x=0;k;k>>=1,x++)
		{
			if(k&1)
			{
				if(B[x]==0)B[x]=j;
				else B[x]&=j;
			}
		}
	}
	for(i=32,j=1u<<31;i--;j>>=1)
	{
		if(B[i]==0||B[i]&(j-1))continue;
		break;
	}
	for(x=y=0;x<n;x++)
	{
		if(A[x]&j)
		{
			A[y++]=A[x];
		}
	}
	printf("%u\n%u",y,A[0]);
	for(i=0;++i<y;)printf(" %u",A[i]);
	putchar('\n');
	return 0;
}