#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define COUNTER_CLOCKWISE -1 //
#define CLOCKWISE 1          //
#define ONLINE_BACK -2       //p2 p0 p1
#define ONLINE_FRONT 2       //p0 p1 p2
#define ON_SEGMENT 0         //p2p0p1

#define EPS 1E-8

class Point
{
public:
    double x, y;
    Point()
    {
    }
    Point(double x, double y)
    {
        (*this).x = x;
        (*this).y = y;
    }

    double operator^(const Point &p) const //
    {
        return x * p.y - y * p.x;
    }

    double operator*(const Point &p) const //
    {
        return x * p.x + y * p.y;
    }

    Point operator*(const double &d) const
    {
        return Point(x * d, y * d);
    }

    Point operator/(const double &d) const
    {
        return Point(x / d, y / d);
    }

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }

    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }

    double sqr()
    {
        return x * x + y * y;
    }
    double abs()
    {
        return sqrt(sqr());
    }

    double distance(const Point &p)
    {
        return fabs((*this - p).abs());
    }

    void print()
    {

        printf("%.8lf %.8lf", x, y);
    }
};

class Line
{
public:
    Point p1, p2;
    Point vec;
    Line()
    {
    }
    Line(Point p1, Point p2)
    {
        (*this).p1 = p1;
        (*this).p2 = p2;
        (*this).vec = p2 - p1;
    }
};

class Circle
{
public:
    Point o;
    double r;
    Circle()
    {
    }

    Circle(Point o, double r)
    {
        (*this).o = o;
        (*this).r = r;
    }

    Circle(double cx, double cy, double r)
    {
        (*this).o.x = cx;
        (*this).o.y = cy;
        (*this).r = r;
    }
};

Point polar(double length, double angle) //
{
    return Point(length * cos(angle), length * sin(angle));
}

pair<Point, Point> get_Cross_Points(Circle c1, Circle c2) //
{

    Point vec12 = c2.o - c1.o; //
    double d = vec12.abs();    //

    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2.0 * c1.r * d)); //vec12c1

    double t = atan2(vec12.y, vec12.x); //vec12x
    return make_pair(c1.o + polar(c1.r, t - a), c1.o + polar(c1.r, t + a));
}
const double pi=3.14159265358979;
double angle(double x,double y)
{
	if(x==0&&y>0) return pi/2;
	if(x==0&&y<0) return 3*pi/2;
	if(x>0&&y==0) return 0;
	if(x<0&&y==0) return pi;
	if(x>0&&y>0) return atan(y/x);
	if(x<0&&y>0) return pi+atan(y/x);
	if(x<0&&y<0) return pi+atan(y/x);
	if(x>0&&y<0) return pi*2+atan(y/x);
}
inline pair<double,double> qwq(Circle c1, Circle c2)
{
	if(c1.o.x==0&&c1.o.y==0) return {-10000,10000};
	if(c1.o.x*c1.o.x+c1.o.y*c1.o.y+EPS>c1.r*c1.r*4) return {1,-1145141919};
	pair<Point, Point> a=get_Cross_Points(c1,c2);
//	cout << a.first.x << " " << a.first.y << " " << a.second.x << " " << a.second.y << "\n";
	double x=angle(a.first.x,a.first.y);
	double y=angle(a.second.x,a.second.y);
	if(x>y) swap(x,y);
	if(y-x>=pi) x+=pi*2,swap(x,y);
	//cout << x << " " << y << "\n";
	return {x,y};
}
Point a[100005];
Circle b[100005];
int n,k;
pair <double,double> c[200005];
priority_queue <double,vector<double>,greater<double> > q;
inline bool check(double x)
{
	for(int i=1;i<=n;i++)
		b[i].o=a[i],b[i].r=x;
	b[0].r=x,b[0].o={0,0};
	for(int i=1;i<=n;i++)
	{
		c[i]=qwq(b[i],b[0]);
		if(c[i].second<c[i].first) c[i].second+=pi*2;
		c[i+n]={c[i].first+pi*2,c[i].second+pi*2};
	//	cout << c[i].first << " " << c[i].second << "*\n";
	}
	while(!q.empty()) q.pop();
	sort(c+1,c+n+n+1);
	for(int i=1;i<=n+n;i++)
	{
		q.push(c[i].second);
		while(!q.empty()&&q.top()<c[i].first) q.pop();
		if(q.size()>=k) return 1;
	}
	return 0;
}
int main()
{
/*    Circle c1, c2;
    cin >> c1.o.x >> c1.o.y >> c1.r;
    cin >> c2.o.x >> c2.o.y >> c2.r;

    auto ans = get_Cross_Points(c1, c2);*/
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    	cin >> a[i].x >> a[i].y;
    double l=0,r=200000;
    while(l+(1e-6)<=r)
    {
    	double mid=(l+r)/2;
  //  	cout << mid << " " << check(mid) << "\n";
    	if(check(mid)) r=mid;
    	else l=mid;
	}
//	cout << "***" << check(1) << "***";
	printf("%.10lf",(l+r)/2);
}