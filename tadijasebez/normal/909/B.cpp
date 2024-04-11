#include <stdio.h>
int max(int a, int b){ return a>b?a:b;}
int sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		int tmp=i*(n-i+1);
		sol=max(sol,tmp);
	}
	printf("%i\n",sol);
	return 0;
}