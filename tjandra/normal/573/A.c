#include<stdio.h>
typedef unsigned u;
u F(u n){while(n%2==0)n/=2;while(n%3==0)n/=3;return n;}
int main()
{
	u t,v,x;
	scanf("%u%u",&t,&x);
	for(v=F(x);--t;)
	{
		scanf("%u",&x);
		if(F(x)!=v)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}