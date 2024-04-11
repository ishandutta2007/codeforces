#include <stdio.h>
#include <cstring>

int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	while(k--)
	{
		if(n%10==0) n/=10;
		else n--;
	}
	printf("%i\n",n);
	return 0;
}