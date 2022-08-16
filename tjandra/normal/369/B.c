#include<stdio.h>
typedef unsigned u;
int main()
{
	u n,k,l,r,Sa,Sk,a,b,c;
	scanf("%u%u%u%u%u%u",&n,&k,&l,&r,&Sa,&Sk);
	Sa-=Sk;n-=k;
	if(n)
	{
		a=Sa%n;b=n-a;
		c=Sa/n;
		while(b--)printf("%u ",c);
		c++;
		while(a--)printf("%u ",c);
	}
	a=Sk%k;b=k-a;
	c=Sk/k;
	while(b--)printf("%u ",c);
	c++;
	while(a--)printf("%u ",c);
	putchar('\n');
	return 0;
}