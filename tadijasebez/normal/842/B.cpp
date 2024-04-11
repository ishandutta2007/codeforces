#include <stdio.h>
#include <cmath>
struct Point
{
	int x,y;
	inline double operator + (const Point &b) const
	{
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
	}
	Point (){}
	Point (int a, int b)
	{
		x=a;
		y=b;
	}
};
int sol;
int main()
{
	int R,D,x,y,r,q;
	scanf("%i %i",&R,&D);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&x,&y,&r);
		double tmp=Point(0,0)+Point(x,y);
		if(tmp-r>=R-D && tmp+r<=R) sol++;
	}
	printf("%i",sol);
	return 0;
}