#include <stdio.h>
#include <cmath>
struct Point
{
        long long x,y;
	inline double operator + (const Point &b) const
	{
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
	}
	Point (){}
	Point (long long a, long long b)
	{
		x=a;
		y=b;
	}
} a,b;
int x[105];
int main()
{
	int n,i,soli,v1,v2;
	scanf("%i %i %i",&n,&v1,&v2);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	scanf("%lld %lld",&a.x,&a.y);
	double sol=200000000.00;
	for(i=2;i<=n;i++)
	{
		b.x=(long long) x[i];
		b.y=0;
		double tmp=(Point(0,0)+b)/v1+(a+b)/v2;
		if(tmp<=sol) soli=i,sol=tmp;
	}
	printf("%i",soli);
	return 0;
}