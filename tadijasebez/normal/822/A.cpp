#include <stdio.h>
int main()
{
	int a,b,i;
	scanf("%i%i",&a,&b);
	if(a<b)
	{
		int sol=1;
		for(i=2;i<=a;i++) sol*=i;
		printf("%i\n",sol);
	}
	else
	{
		int sol=1;
		for(i=2;i<=b;i++) sol*=i;
		printf("%i\n",sol);
	}
	return 0;
}