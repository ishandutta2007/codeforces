#include <stdio.h>
int main()
{
	int n,i,j;
	scanf("%i",&n);
	i=n/2;
	if(n%2==1){printf("7"); i--;}
	for(j=0;j<i;j++)
	{
		printf("1");
	}
	return 0;
}