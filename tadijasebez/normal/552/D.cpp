#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point
{
	int x,y;
	inline bool operator < (const Point &b) const
	{
		if(y==b.y) return x<b.x;
		return y<b.y;
	}
} points[2050],p0;
int Orientation(Point p, Point q, Point r)
{
	int o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	return 2;
}
int DistSq(Point a, Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool Compare(Point a, Point b)
{
	int o=Orientation(p0,a,b);
	if(o==0) return DistSq(p0,a)<DistSq(p0,b);
	if(o==2) return true;
	return false;
}
int sol;
int main()
{
	int n,m,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i %i",&points[i].x,&points[i].y);
	sort(points,points+n);
	for(i=0;i<n;i++)
	{
		p0=points[i];
		sort(points+i+1,points+n,Compare);
		m=0;
		for(j=i+1;j<n;j++)
		{
			sol+=m;
			if(!(j<n-1 && Orientation(p0,points[j],points[j+1])==0)) m=j-i;
		}
		sort(points+i+1,points+n);
	}
	printf("%i\n",sol);
	return 0;
}