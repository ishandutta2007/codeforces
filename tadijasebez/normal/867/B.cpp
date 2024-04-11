#include <stdio.h>
int main()
{
	int x,n;
	scanf("%i",&x);
	if(x==1)
	{
		printf("1 1\n1\n");
		return 0;
	}
	n=x*2-2;
	printf("%i 2\n",n);
	printf("1 2\n");
	return 0;
}