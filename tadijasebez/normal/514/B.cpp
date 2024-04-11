#include <stdio.h>
struct Point
{
	int x,y;
} points[1000],p0;
int Orientation(Point p, Point q, Point r)
{
	int o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	else return 2;
}
bool mark[1000];
int sol;
int main()
{
	int n,i,j;
	scanf("%i %i %i",&n,&p0.x,&p0.y);
	for(i=0;i<n;i++) scanf("%i %i",&points[i].x,&points[i].y);
	for(i=0;i<n;i++)
	{
		if(mark[i]) continue;
		sol++;
		for(j=i+1;j<n;j++)
		{
			if(Orientation(p0,points[i],points[j])==0) mark[j]=true;
		}
	}
	printf("%i\n",sol);
	return 0;
}