#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
int sol=10000;
int main()
{
	int n,t,x,i;
	scanf("%i %i",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		x=86400-x;
		t-=x;
		if(t<=0) sol=min(sol,i);
	}
	printf("%i\n",sol);
	return 0;
}