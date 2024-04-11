#include <stdio.h>
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int sol=0;
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		sol=max(sol,min(x-1,1000000-x));
	}
	printf("%i\n",sol);
	return 0;
}