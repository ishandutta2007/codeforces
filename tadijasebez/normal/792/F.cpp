#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
const int p=1e6;
const long double cnt=1e-8;
struct Point
{
	long double x,y;
	Point(){}
	Point(long double a, long double b)
	{
		x=a;
		y=b;
	}
	bool operator<(const Point &r)const{return x==r.x?y<r.y:x<r.x;}
	Point operator-(const Point &r)const{return Point(x-r.x,y-r.y);}
	long double operator*(const Point &r)const{return x*r.y-y*r.x;}
	/*inline bool operator<(const Point &b) const
	{
		if(x<b.x) return true;
		if(x==b.x && y<b.y) return true;
		return false;
	}
	Point operator-(const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}
	long double operator*(const Point &b) const
	{
		return x*b.y-y*b.x;
	}*/
};
bool above(Point a, Point b, Point c)
{
	return (b-a)*(c-a)<=cnt;
}
set<Point> points;
int main()
{
	int q,i,lasti=0,t,x,y;
	long long m;
	scanf("%i %lld",&q,&m);
	points.insert(Point(0,0));
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&t,&x,&y);
		x=(x+lasti)%p+1;
		y=(y+lasti)%p+1;
		if(t==1)
		{
			set<Point>::iterator it,last,next,pre;
			it=points.lower_bound(Point(x,0));
			if(it!=points.end() && it->y<=y)
				continue;
			last=it;
			last--;
			if(it!=points.end() && above(*last,Point(x,y),*it))
				continue;
			it=points.insert(Point(x,y)).first;
			next=last=it;
			pre=--last;
			pre--;
			next++;
			while(next!=points.end() && next->x==x)
				points.erase(next++);
			while(last!=points.begin() && above(*pre,*last,*it))
				points.erase(last--),pre--;
		}
		else
		{
			set<Point>::iterator it,it2;
			it=points.lower_bound(Point(1.0*y/x,0));
			bool good=false;
			if(it!=points.end())
			{
				if(it->y*x<=m)
				{
					good=true;
				}
				else
				{
					it2=it;
					it2--;
					if(above(Point(it2->x*x,it2->y*x),Point(y,m),Point(it->x*x,it->y*x)))
					{
						good=true;
					}
				}
			}
			if(good) printf("YES\n"),lasti=i;
			else printf("NO\n");
		}
	}
	return 0;
}