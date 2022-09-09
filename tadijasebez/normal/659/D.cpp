#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point
{
	int x,y;
} points[1050];
int sol;
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	for(i=0;i<n+1;i++) scanf("%i %i",&points[i].x,&points[i].y);
	for(i=1;i<n;i++)
	{
		if(points[i-1].y<points[i].y && points[i].x>points[i+1].x) sol++;
		else if(points[i-1].x<points[i].x && points[i].y<points[i+1].y) sol++;
		else if(points[i-1].y>points[i].y && points[i].x<points[i+1].x) sol++;
		else if(points[i-1].x>points[i].x && points[i].y>points[i+1].y) sol++;
	}
	printf("%i\n",sol);
	return 0;
}