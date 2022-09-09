#include <stdio.h>
int main()
{
	int a,b,c,i;
	scanf("%i %i %i",&a,&b,&c);
	a*=10;
	for(i=1;i<=10000000;i++)
	{
		int cif=a/b;
		if(cif==c) return printf("%i\n",i),0;
		a=a%b;
		a*=10;
	}
	printf("-1\n");
	return 0;
}