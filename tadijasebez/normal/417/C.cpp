#include <stdio.h>
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	if(n*k>n*(n-1)/2) return printf("-1\n"),0;
	printf("%i\n",n*k);
	for(i=0;i<n;i++)
	{
		for(j=1;j<=k;j++)
		{
			printf("%i %i\n",i+1,(i+j)%n+1);
		}
	}
	return 0;
}