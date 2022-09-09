#include <stdio.h>
double min(double a, double b){ return a>b?b:a;}
double sol=1e15;
int main()
{
	int n,m,i,a,b;
	scanf("%i %i",&n,&m);
	while(n--) scanf("%i %i",&a,&b),sol=min(sol,(double)a*m/b);
	printf("%.12llf\n",sol);
	return 0;
}