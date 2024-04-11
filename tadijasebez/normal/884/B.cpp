#include <stdio.h>
int main()
{
	int n,x,sum=0,y,i;
	scanf("%i %i",&n,&x);
	for(i=1;i<=n;i++) scanf("%i",&y),sum+=y;
	if(n-1==x-sum) printf("YES\n");
	else printf("NO\n");
	return 0;
}