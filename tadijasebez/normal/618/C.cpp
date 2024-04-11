#include <stdio.h>
struct Point
{
	long long x,y;
	int index;
	inline bool operator < (const Point &b) const
	{
		if(y==b.y) return x<b.x;
		return y<b.y;
	}
} points[100007];
int Orientation(Point p, Point q, Point r)
{
	long long o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	return 2;
}
long long distSq(Point a, Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool Compare1(Point a, Point b)
{	
	int o=Orientation(points[0],a,b);
	if(o==0) return distSq(points[0],a)<distSq(points[0],b);
	if(o==2) return true;
	return false;
}
bool Compare2(Point a, Point b)
{
	int o=Orientation(points[1],a,b);
	if(o==0) return distSq(points[1],a)<distSq(points[1],b);
	if(o==1) return true;
	return false;
}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++) 
		scanf("%lld %lld",&points[i].x,&points[i].y),points[i].index=i+1;
	j=0;
	for(i=1;i<n;i++)
	{
		if(points[i]<points[j]) j=i;
	}
	Point tmp;
	tmp=points[0];
	points[0]=points[j];
	points[j]=tmp;
	j=1;
	for(i=2;i<n;i++)
	{
		if(Compare1(points[i],points[j])) j=i;
	}
	tmp=points[1];
	points[1]=points[j];
	points[j]=tmp;
	j=2;
	for(i=3;i<n;i++)
	{
		if(Compare2(points[i],points[j])) j=i;
	}
	printf("%i %i %i\n",points[0].index,points[1].index,points[j].index);
	return 0;
}