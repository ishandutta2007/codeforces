#include <stdio.h>
#include <vector>
using namespace std;
struct Point
{
	int x,y;
	Point operator + (const Point &b) const
	{
		Point c;
		c.x=x+b.x;
		c.y=y+b.y;
		return c;
	}
	Point operator - (const Point &b) const
	{
		Point c;
		c.x=x-b.x;
		c.y=y-b.y;
		return c;
	}
	bool operator == (const Point &b) const
	{
		if(x!=b.x) return false;
		if(y!=b.y) return false;
		return true;
	}
} Points[3],p1,p2,p3,p4;
vector<Point> sol;
vector<Point> out;
int main()
{
	int i,j;
	for(i=0;i<3;i++) scanf("%i %i",&Points[i].x,&Points[i].y);
	p1=Points[0];
	p2=Points[1];
	p3=Points[2];
	p4=p3+p1-p2;
	sol.push_back(p4);
	p1=Points[2];
	p2=Points[0];
	p3=Points[1];
	p4=p3+p1-p2;
	sol.push_back(p4);
	p1=Points[1];
	p2=Points[2];
	p3=Points[0];
	p4=p3+p1-p2;
	sol.push_back(p4);
	for(i=0;i<3;i++)
	{
		bool ok=true;
		for(j=i+1;j<3;j++)
		{
			if(sol[i]==sol[j]) ok=false;
		}
		if(ok) out.push_back(sol[i]);
	}
	printf("%i\n",out.size());
	for(i=0;i<out.size();i++) printf("%i %i\n",out[i].x,out[i].y);
	return 0;
}