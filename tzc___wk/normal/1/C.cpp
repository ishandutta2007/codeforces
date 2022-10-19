#include<iostream>
#include<cmath>
#include <math.h>
#include<cstdio>
#define M_PI 3.1415926535897
using namespace std;
double xa,ya,xb,yb,xc,yc;
double a,b,c,A,B,C,x,y;
double length(double x,double y){return x*x+y*y; } 
double gcd(double a,double b){ return fabs(b)<1E-4?a:gcd(b,fmod(a,b));}
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
	y=length(xc,yc);
	a=xa-xc,b=ya-yc,c=(length(xa,ya)-y)*0.5;
	A=xb-xc,B=yb-yc,C=(length(xb,yb)-y)*0.5;
	y=1/(a*B-A*b);
	x=(c*B-C*b)*y,y*=a*C-A*c;
	a=atan2(ya-=y,xa-=x);
	b=atan2(yb-=y,xb-=x);
	c=atan2(yc-=y,xc-=x);
	a=gcd(gcd(fabs(b-a),fabs(c-a)),2*M_PI);
	printf("%.100lf",length(xa,ya)*sin(a)*M_PI/a); 
	return 0;
}