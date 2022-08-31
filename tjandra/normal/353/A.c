#include<stdio.h>
typedef unsigned u;
int main()
{
	u t,a,b,A=0,B=0,r=0;
	for(scanf("%u",&t);t--;)
	{
		scanf("%u%u",&a,&b);
		A^=a&1;B^=b&1;
		r|=(a^b)&1;
	}
	printf((A^B)?"-1\n":(A&r)?"1\n":(!A)?"0\n":"-1\n");
	return 0;
}