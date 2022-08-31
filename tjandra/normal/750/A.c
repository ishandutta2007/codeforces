#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
int main()
{
	u n,k,j=1,r=0;
	scanf("%u%u",&n,&k);
	for(k=(240-k)/5;k>=j;k-=j++)++r;
	if(r>n)r=n;
	printf("%u\n",r);
	return 0;
}