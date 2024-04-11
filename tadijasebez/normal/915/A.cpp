#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
int sol=1000000;
int main()
{
	int n,k,x;
	scanf("%i %i",&n,&k);
	while(n--)
	{
		scanf("%i",&x);
		if(k%x) continue;
		sol=min(sol,k/x);
	}
	printf("%i\n",sol);
	return 0;
}