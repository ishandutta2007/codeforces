#include <iostream>
#include <cmath>
#define sqr(s)	((s)*(s))
using namespace std;
const double EPS=1e-3;
const double pi=3.1415926535897932384626433832795028841971694;
double gcd(double a,double b)
{
	if (a<EPS) return b;
	if (b<EPS) return a;
	return gcd(b,fmod(a,b));	
}
int main()
{
	double xx1,yy1,xx2,xx3,yy2,yy3;
	cin>>xx1>>yy1;
	cin>>xx2>>yy2;
	cin>>xx3>>yy3;
	double a=sqrt(sqr(xx1-xx2)+sqr(yy1-yy2));
	double b=sqrt(sqr(xx3-xx2)+sqr(yy3-yy2));
	double c=sqrt(sqr(xx1-xx3)+sqr(yy1-yy3));
	double p=(a+b+c)/2;
	double r=a*b*c/4/sqrt(p*(p-a)*(p-b)*(p-c));
	double aa=acos((2*sqr(r)-sqr(a))/2/r/r);
	double bb=acos((2*sqr(r)-sqr(b))/2/r/r);
	double cc=2*pi-aa-bb;
	double o=gcd(gcd(aa,bb),cc);
	printf("%.8lf",sin(o)*(pi/o)*r*r);
}