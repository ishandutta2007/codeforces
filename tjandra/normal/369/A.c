#include<stdio.h>
typedef unsigned u;
int main()
{
	u n,m,k,s=0,d=0,i,r=0;
	scanf("%u%u%u",&n,&m,&k);
	while(n--)
	{
		scanf("%u",&i);
		if(i==1)s++;
		if(i==2)d++;
	}
	if(s>m)r=s-m;
	else k+=m-s;
	if(d>k)r+=d-k;
	printf("%u\n",r);
	return 0;
}