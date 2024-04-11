#include <stdio.h>
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	n=n%m;
	for(i=0;i<10000000;i++)
	{
		n*=2;
		if(n>=m) n-=m;
	}
	if(n) printf("No\n");
	else printf("Yes\n");
	return 0;
}