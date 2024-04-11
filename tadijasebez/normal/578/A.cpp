#include <stdio.h>
int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(a<b) printf("-1\n");
	else printf("%.12llf\n",(a+b)/(2.00*((a+b)/(2*b))));
	return 0;
}