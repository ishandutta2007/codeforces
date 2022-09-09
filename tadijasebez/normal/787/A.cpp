#include <stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%i %i",&a,&b);
	scanf("%i %i",&c,&d);
	for(int i=0;i<10000000;i++)
	{
		if(i>=b && i>=d && (i-b)%a==0 && (i-d)%c==0)
		{
			printf("%i\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}