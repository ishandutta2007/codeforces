#include<bits/stdc++.h>
using namespace std;
const double eps=1e-12;
struct pt
{
	double x,y;
	void rd()
	{
		scanf("%lf%lf",&x,&y);
	}
}a,b,c;
double dis(pt a,pt b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double ab,bc,ac,tb,tc,l,r,lm,rm;
double sol(double k)
{
	pt u={k*b.x+(1-k)*c.x,k*b.y+(1-k)*c.y};
	double au=dis(a,u),bu=dis(b,u),cu=dis(c,u);
	if(au+bu<tb&&au+cu<tc)
		return min(tb-bu,tc-cu);
	double l=0,r=1;
	for(int z=0;z<100;z++)
	{
		double m=(l+r)/2;
		pt v={m*u.x+(1-m)*a.x,m*u.y+(1-m)*a.y};
		if(m*au+dis(b,v)<tb&&m*au+dis(c,v)<tc)
			l=m;
		else
			r=m;
	}
	return (l+r)/2*au;
}
int main()
{
	scanf("%lf%lf",&tb,&tc);
	a.rd(),c.rd(),b.rd();
	ab=dis(a,b),ac=dis(a,c),bc=dis(b,c);
	tc+=ac+eps,tb+=ab+eps;
	if(tc>ab+bc)
	{
		printf("%.9lf\n",min(tb+bc,tc));
		return 0;
	}
	l=0,r=1;
	for(int z=0;z<100;z++)
	{
		lm=(2*l+r)/3,rm=(l+2*r)/3;
		if(sol(lm)>sol(rm))
			r=rm;
		else
			l=lm;
	}
	printf("%.9lf\n",sol((l+r)/2));
	return 0;
}