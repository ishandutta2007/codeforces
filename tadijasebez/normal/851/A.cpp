#include <stdio.h>
int main()
{
	int n,k,t;
	scanf("%i %i %i",&n,&k,&t);
	if(t>n) printf("%i\n",k-(t-n));
	else if(t<k) printf("%i\n",t);
	else printf("%i\n",k);
	return 0;
}