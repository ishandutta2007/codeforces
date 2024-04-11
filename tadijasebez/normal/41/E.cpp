#include <stdio.h>
int main()
{
	int n,i,j,m;
	scanf("%i",&n);
	printf("%i\n",(n/2)*(n-n/2));
	m=n/2;
	for(i=1;i<=m;i++)
		for(j=m+1;j<=n;j++)
			printf("%i %i\n",i,j);
	return 0;
}