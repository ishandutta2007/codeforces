#include <stdio.h>
int main()
{
	int sol=0,n,x,i,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&x),sol+=(x<=5-k);
	printf("%i\n",sol/3);
	return 0;
}