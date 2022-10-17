#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
struct P
{
	double x,y;
	void scan()
	{
		scanf("%lf %lf",&x,&y);
	}
	double dis(P&a)
	{
		return hypot(x-a.x,y-a.y);
	}
}a,b,c;
double ab,bc,ac,tb,tc,l,r,lm,rm;
double cal(double k)
{
	P u=(P){k*b.x+(1-k)*c.x,k*b.y+(1-k)*c.y};
	double au=a.dis(u),ub=u.dis(b),uc=u.dis(c);
	if(au+ub<tb&&au+uc<tc)
		return min(tb-ub,tc-uc);
	double l=0,r=1,m;
	for(int i=0;i<99;i++)
	{
		m=(l+r)*.5;
		P v=(P){m*u.x+(1-m)*a.x,m*u.y+(1-m)*a.y};
		if(m*au+v.dis(b)<tb&&m*au+v.dis(c)<tc)
			l=m;
		else
			r=m;
	}
	return (l+r)*.5*au;
}
int main()
{
	scanf("%lf %lf",&tb,&tc);
	a.scan(),c.scan(),b.scan();
	ab=a.dis(b),ac=a.dis(c),bc=b.dis(c);
	tc+=ac+1e-12,tb+=ab+1e-12;
	if(tc>ab+bc)
		return printf("%.9lf",min(tb+bc,tc)),0;
	l=0,r=1;
	for(int i=0;i<99;i++)
	{
		lm=(2*l+r)/3,rm=(l+2*r)/3;
		if(cal(lm)>cal(rm))
			r=rm;
		else
			l=lm;
	}
	printf("%.8lf",cal((l+r)*.5));
	return 0;
}