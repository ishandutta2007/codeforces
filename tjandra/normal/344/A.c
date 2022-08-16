#include<stdio.h>
typedef unsigned u;
int main()
{
	u t,n,p,g=1;
	for(scanf("%u%u",&t,&p);--t;p=n)
	{
		scanf("%u",&n);
		if(n!=p)g++;
	}
	printf("%u\n",g);
	return 0;
}