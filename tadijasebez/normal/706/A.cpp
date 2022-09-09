#include <stdio.h>
#include <cmath>
struct Point
{
	double x,y;
} p1,p2;
double dist(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double sol=10000000.00,v;
double min(double a, double b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	int n,i,x,y,w;
	scanf("%i %i",&x,&y);
	p1.x=(double) x;
	p1.y=(double) y;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i %i",&x,&y,&w);
		p2.x=(double) x;
		p2.y=(double) y;
		v=(double) w;
		sol=min(sol,dist(p1,p2)/v);
	}
	printf("%.12llf\n",sol);
	return 0;
}