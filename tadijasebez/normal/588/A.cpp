#include <stdio.h>
const int N=100050;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,x,y,sol=0,Min=N;
	scanf("%i",&n);
	while(n--) scanf("%i %i",&x,&y),Min=min(Min,y),sol+=x*Min;
	printf("%i\n",sol);
	return 0;
}