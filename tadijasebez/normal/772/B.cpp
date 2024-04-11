#include <stdio.h>
#include <cmath>
struct Point
{
	long long x,y;
	inline double operator + (const Point &b) const
	{
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
	}	
} points[1050];
double TriangleArea(Point a, Point b, Point c)
{
	double s=((a+b)+(a+c)+(b+c))*0.5;
	return sqrt(s*(s-(a+b))*(s-(a+c))*(s-(b+c)));
}
double Heigth(Point a, Point b, Point c)
{
	return TriangleArea(a,b,c)/(a+c);
}
int main()
{
	double sol=2000000000.00;
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%lld %lld",&points[i].x,&points[i].y);
	int prev=n-1,next;
	for(i=0;i<n;i++)
	{
		next=(i+1)%n;
		double h=Heigth(points[prev],points[i],points[next]);
		//h*=0.5;
		//printf("%.12llf %.12llf %.12llf\n",h,TriangleArea(points[prev],points[i],points[next]),points[prev]+points[next]);
		if(sol>h) sol=h;
		prev=i;
	}
	printf("%.12llf\n",sol);
	return 0;
}