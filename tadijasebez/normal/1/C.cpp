#include <stdio.h>
#include <cmath>
const double pi=acos(-1);
const double eps=1e-4;
double a,b,c,x[3],y[3],r,angle,alpha,beta,gamma,s,p,area;
double gcd(double x, double y)
{
	if(fabs(y)<eps) return x;
	return gcd(y,fmod(x,y));
}
double gcd(double a, double b, double c){ return gcd(a,gcd(b,c));}
int main()
{
	int i;
	for(i=0;i<3;i++) scanf("%lf %lf",&x[i],&y[i]);
	a=sqrt((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]));
	b=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
	c=sqrt((x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0]));
	s=(a+b+c)/2.0;
	p=sqrt(s*(s-a)*(s-b)*(s-c));
	r=(a*b*c)/(4*p);
	alpha=2*asin(a/(2*r));
	beta=2*asin(b/(2*r));
	gamma=2*pi-alpha-beta;
	angle=gcd(alpha,beta,gamma);
	area=pi*r*r*sin(angle)/angle;
	printf("%.6lf\n",area);
	return 0;
}