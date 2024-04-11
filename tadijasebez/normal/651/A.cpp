#include <stdio.h>
int sol;
int main()
{
	int a,b;
	scanf("%i %i",&a,&b);
	while(a>0 && b>0)
	{
		sol++;
		if(a<b)
		{
			a++;
			b-=2;
		}
		else
		{
			b++;
			a-=2;
		}
	}
	if(a<0 || b<0) sol--;
	printf("%i\n",sol);
	return 0;
}