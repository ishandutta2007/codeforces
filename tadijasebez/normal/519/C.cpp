#include <stdio.h>
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int a,b;
	scanf("%i %i",&a,&b);
	int sol=0;
	while(a && b && a+b>2)
	{
		sol++;
		if(a<b) a--,b-=2;
		else a-=2,b--;
	}
	printf("%i\n",sol);
	return 0;
}