#include <stdio.h>
#include <cmath>
struct Point
{
	int x,y;
} Points[100];
double dist(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double sol;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%i %i",&Points[i].x,&Points[i].y);
		if(i!=0)
		{
			sol+=dist(Points[i],Points[i-1]);
		}
	}
	sol=(sol*(double)k)/50.00;
	printf("%.12llf\n",sol);
	return 0;
}