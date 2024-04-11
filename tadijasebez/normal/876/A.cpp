#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,a,b,c;
	scanf("%i %i %i %i",&n,&a,&b,&c);
	if(n==1) return printf("0\n"),0;
	n-=2;
	int sol=min(a,b);
	sol+=n*min(c,min(a,b));
	printf("%i\n",sol);
	return 0;
}