#include <stdio.h>
int main()
{
	int n,x,i,y;
	scanf("%i %i",&n,&x);
	if(n==2 && x==0)
	{
		printf("NO\n");
		return 0;
	}
	if(n==1)
	{
		printf("YES\n");
		printf("%i\n",x);
		return 0;
	}
	if(n==2)
	{
		printf("YES\n");
		printf("%i 0\n",x);
		return 0;
	}
	printf("YES\n");
	y=0;
	for(i=1;i<=n-3;i++)
	{
		printf("%i ",i);
		y^=i;
	}
	y^=1<<17;
	y^=1<<18;
	printf("%i %i %i\n",1<<17,1<<18,y^x);
	return 0;
}