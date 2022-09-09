#include <stdio.h>
struct Point
{
	long long x,y;
	inline long long operator + (const Point &b) const
	{
		return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	}
} a,b,c;
bool Collinear(Point p, Point q, Point r)
{
	return (q.y-p.y)*(r.x-q.x)==(q.x-p.x)*(r.y-q.y);
}
int main()
{
	scanf("%lld %lld %lld %lld %lld %lld",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	if(a+b==b+c && !Collinear(a,b,c)) printf("Yes\n");
	else printf("No\n");
	return 0;
}