#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const double PI=acos(-1);
struct Point
{
	int x,y;
	Point (){}
	Point (int a, int b)
	{
		x=a;
		y=b;
	}
};
int Orientation(Point p, Point q, Point r)
{
	int o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	return 2;
}
int DistSq(Point p, Point q)
{
	return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}
bool Compare(Point a, Point b)
{
	int o=Orientation(Point(0,0),a,b);
	if(o==0) return DistSq(Point(0,0),a)<DistSq(Point(0,0),b);
	if(o==2) return true;
	return false;
}
vector<Point> q[5];
vector<Point> v,v1;
double Angle(Point a)
{
	double rad,angle=0;
	if(a.x>0 && a.y>=0)
	{
		rad=atan((double)a.y/a.x);
		angle=rad*180.00/PI;
	}
	else if(a.x>0 && a.y<0)
	{
		rad=atan((double)(-a.y)/a.x);
		angle=360.00-rad*180.00/PI;
	}
	else if(a.x<0 && a.y>=0)
	{
		rad=atan((double)a.y/(-a.x));
		angle=180.00-rad*180.00/PI;
	}
	else if(a.x<0 && a.y<0)
	{
		rad=atan((double)(-a.y)/(-a.x));
		angle=180.00+rad*180.00/PI;
	}
	else if(a.x==0 && a.y>=0)
	{
		angle=90.00;
	}
	else if(a.x==0 && a.y<0)
	{
		angle=270.00;
	}
	return angle;
}
double abs(double a)
{
	if(a<0) return -a;
	else return a;
}
double min(double a, double b)
{
	if(a>b) return b;
	else return a;
}
double max(double a, double b)
{
	if(a>b) return a;
	else return b;
}
double Angle(Point a, Point b)
{
	double aa=Angle(a),bb=Angle(b);
	//return min(abs(aa-bb),360.00-max(aa,bb)+min(aa,bb));
	//return 360.00-max(aa,bb)+min(aa,bb);
	double ret=bb-aa;
	if(ret<0) ret+=360.00;
	return ret;
}
int main()
{
	int n,i,x,y,c=0;
	scanf("%i",&n);
	if(n==2)
	{
	//	return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%i %i",&x,&y);
		if(x>=0 && y>=0)
		{
			if(q[1].empty()) c++;
			q[1].push_back(Point(x,y));
		}
		else if(x>=0)
		{
			if(q[2].empty()) c++;
			q[2].push_back(Point(x,y));
		}
		else if(y>=0)
		{
			if(q[3].empty()) c++;
			q[3].push_back(Point(x,y));
		}
		else
		{
			if(q[4].empty()) c++;
			q[4].push_back(Point(x,y));
		}
	}
	sort(q[1].begin(),q[1].end(),Compare);
	sort(q[2].begin(),q[2].end(),Compare);
	sort(q[3].begin(),q[3].end(),Compare);
	sort(q[4].begin(),q[4].end(),Compare);
	for(i=0;i<q[4].size();i++) v1.push_back(q[4][i]);
	for(i=0;i<v1.size();i++)
	{
		if(!(i<v1.size()-1 && Orientation(Point(0,0),v1[i],v1[i+1])==0))
			v.push_back(v1[i]);
	}
	v1.clear();
	for(i=0;i<q[2].size();i++) v1.push_back(q[2][i]);
	for(i=0;i<v1.size();i++)
	{
		if(!(i<v1.size()-1 && Orientation(Point(0,0),v1[i],v1[i+1])==0))
			v.push_back(v1[i]);
	}
	v1.clear();
	for(i=0;i<q[1].size();i++) v1.push_back(q[1][i]);
	for(i=0;i<v1.size();i++)
	{
		if(!(i<v1.size()-1 && Orientation(Point(0,0),v1[i],v1[i+1])==0))
			v.push_back(v1[i]);
	}
	v1.clear();
	for(i=0;i<q[3].size();i++) v1.push_back(q[3][i]);
	//for(i=0;i<v.size();i++) printf("%i %i\n",v[i].x,v[i].y);
	for(i=0;i<v1.size();i++)
	{
		if(!(i<v1.size()-1 && Orientation(Point(0,0),v1[i],v1[i+1])==0))
			v.push_back(v1[i]);
	}
	double MinAngle=360.00,MaxAngle=0.00;
	for(i=0;i<v.size();i++)
	{
		int next=(i+1)%v.size();
		double tmp=Angle(v[i],v[next]);
		//printf("%i %i %i %i %.12llf\n",v[i].x,v[i].y,v[next].x,v[next].y,tmp);
		if(MinAngle>tmp) MinAngle=tmp;
		if(MaxAngle<tmp) MaxAngle=tmp;
	}
	if(v.size()==1) printf("%.12llf\n",0.00);
	else if(v.size()<=2) printf("%.12llf\n",MinAngle);
	else printf("%.12llf\n",360-MaxAngle);
	//if(n==250) printf("%i",v.size());//printf("%.12llf %.12llf\n",MinAngle,MaxAngle);
	return 0;
}