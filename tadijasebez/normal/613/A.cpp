#include <stdio.h>
#include <cmath>
const double PI=acos(-1);
struct Point
{
	 long long x,y;
} p,q[100050];
double Dist(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double top,bot=1000000000.00,dist,sol;
double min(double a, double b)
{
	if(a>b) return b;
	else return a;
}
double max(double a, double b)
{
	if(a>b) return a;
	else return b;
}
double TriangleArea(double a, double b, double c)
{
	double s=(a+b+c)*0.5;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
	int n,i;
	scanf("%i %lld %lld",&n,&p.x,&p.y);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&q[i].x,&q[i].y);
		dist=Dist(p,q[i]);
		top=max(top,dist);
		bot=min(bot,dist);
	}
	for(i=0;i<n;i++)
	{
		int next=(i+1)%n;
		double dist=TriangleArea(Dist(p,q[i]),Dist(p,q[next]),Dist(q[i],q[next]))/(0.5*Dist(q[i],q[next]));
		if ((q[i].x-p.x)*((q[i].x-p.x)-(q[next].x-p.x))+(q[i].y-p.y)*((q[i].y-p.y)-(q[next].y-p.y))<0) continue;
		if ((q[next].x-p.x)*((q[next].x-p.x)-(q[i].x-p.x))+(q[next].y-p.y)*((q[next].y-p.y)-(q[i].y-p.y))<0) continue;
		bot=min(bot,dist);
	}
	sol=top*top*PI-bot*bot*PI;
	printf("%.15llf\n",sol);
	return 0;
}