#include<stdio.h>
typedef double d;
int main()
{
	double m,R,a,b;
	int M,i;
	scanf("%lf%lf",&m,&R);
	a=2*R/m;M=m;b=R*1.4142135623730950488;
	if(M>1)a+=2*(1-1/m)*((2*R+b)/m);b*=2;
	for(i=2;i<M;i++)a+=2*(1-i/m)*((2*(i-1)*R+b)/m);
	printf("%.10lf\n",a);
	return 0;
}