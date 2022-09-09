#include <stdio.h>
struct Point
{
	long long x,y;
} p1,p2,p3,p4;
int Orientation(Point p, Point q, Point r)
{
	long long o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	else return 2;
}
int sol;
int main()
{
	int n,i;
	long long a,b,c;
	scanf("%lld %lld",&p1.x,&p1.y);
	scanf("%lld %lld",&p2.x,&p2.y);
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		if(b==0)
		{
			p3.x=-c/a;
			p3.y=-1e7;
			p4.x=-c/a;
			p4.y=1e7;
		}
		else
		{
			p3.x=-1e7;
			p3.y=(-a*p3.x-c)/b;
			p4.x=1e7;
			p4.y=(-a*p4.x-c)/b;
		}
		if(Orientation(p3,p1,p4)!=Orientation(p3,p2,p4)) sol++;
	}
	printf("%i\n",sol);
	return 0;
}