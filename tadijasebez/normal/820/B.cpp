#include <stdio.h>
double alpha,beta;
double abs(double a)
{
	if(a<0) return -a;
	else return a;
}
int main()
{
	int n,i,a,sol=1;
	scanf("%i %i",&n,&a);
	alpha=180.00-(360.00/n);
	beta=alpha/(n-2);
	for(i=2;i<=n-2;i++)
	{
		if(abs(beta*i-a)<abs(beta*sol-a)) sol=i;
	}
	printf("2 1 %i\n",sol+2);
	return 0;
}