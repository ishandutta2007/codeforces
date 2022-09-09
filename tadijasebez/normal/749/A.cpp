#include <stdio.h>
int main()
{
	int n,i;
	scanf("%i",&n);
	printf("%i\n",n/2);
	for(i=1;i<=n/2;i++) printf("%i ",2+(i==1 && (n&1)));
	return 0;
}