#include <stdio.h>
int sol=1000000000;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		j=(n+i-1)/i;
		sol=min(sol,i+j);
	}
	printf("%i\n",sol*2);
	return 0;
}