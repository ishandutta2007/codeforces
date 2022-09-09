#include <stdio.h>
int a[10],sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,x,d=1;
	scanf("%i",&n);
	while(n>0)
	{
		x=n%10;
		n/=10;
		sol=max(sol,x);
		for(i=0;i<x;i++)
			a[i]+=d;
		d*=10;
	}
	printf("%i\n",sol);
	for(i=0;i<sol;i++) printf("%i ",a[i]);
	return 0;
}