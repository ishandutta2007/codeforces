#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
const double EPS=1e-9;
const double Pi=acos(-1.0);
struct Point
{
	double x,y;
	Point(double xx=0,double yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	Point operator*(double d){return Point(x*d,y*d);}
	Point operator/(double d){return Point(x/d,y/d);}
	double dot(Point p){return x*p.x+y*p.y;}
	double det(Point p){return x*p.y-y*p.x;}
	double abs2(){return x*x+y*y;}
	double abs(){return sqrt(abs2());}
	double alpha(){return atan2(y,x);}
	Point rot90(){return Point(-y,x);}
	Point unit(){return *this/abs();}
};
struct Line
{
	Point p1,p2;
	Line(){}
	Line(Point pp1,Point pp2){p1=pp1,p2=pp2;}
	Point&operator[](int i){return i==0?p1:p2;}
	Point dir(){return p2-p1;}
	bool include(Point p){return (p1-p).det(p2-p)>=-EPS;}
	Line push(double d)
	{
		Point dir=(p2-p1).rot90().unit()*d;
		return Line(p1-dir,p2-dir);
	}
};
Point isLL(Point p1,Point p2,Point q1,Point q2)
{
	double a=(q1-p1).det(p2-p1);
	double b=(p2-p1).det(q2-p1);
//	printf("isLL((%lf,%lf)->(%lf,%lf),(%lf,%lf)->(%lf,%lf))\n",p1.x,p1.y,p2.x,p2.y,q1.x,q1.y,q2.x,q2.y);
	Point ans=(q1*b+q2*a)/(a+b);
//	printf("(%lf,%lf)\n",ans.x,ans.y);
	return ans;
}
Point isLL(Line a,Line b)
{
	return isLL(a[0],a[1],b[0],b[1]);
}
bool parallel(Point p1,Point p2,Point q1,Point q2)
{
	return abs((p2-p1).det(q1-p1)-(p2-p1).det(q2-p1))<EPS;
}
bool parallel(Line l1,Line l2)
{
	return parallel(l1[0],l1[1],l2[0],l2[1]);
}
bool sameDir(Line l1,Line l2)
{
	return parallel(l1,l2)&&l1.dir().dot(l2.dir())>0;
}
bool onright(Line l,Point p) {
	if ((p - l[0]).det(l.dir()) > -EPS) return true;
	else return false;
}
Line plane[1005];
Point p[305],ans[305];
int n,sa[1005],maxr[305];
bool HalfPlane(int ll,int rr,Point&res)
{
	static Point p[1005];
	static Line q[1005];
	int l=0,r=-1;
	for(int t=1;t<=2*n;t++)
	{
		if(sa[t]>n)
		{
			if(ll<=rr&&(sa[t]-n<ll||sa[t]-n>rr))continue;
			if(ll>rr&&(sa[t]-n<ll&&sa[t]-n>rr))continue;
		}
		Line now=plane[sa[t]];
		while(l<r&&onright(now,p[r]))r--;
		while(l<r&&onright(now,p[l+1]))l++;
		if(fabs(now.dir().alpha()-q[r].dir().alpha())<=EPS)continue;
		if(now.dir().alpha()-q[r].dir().alpha()>=Pi-EPS)return false;
		q[++r]=now;
		if(l<r)p[r]=isLL(q[r],q[r-1]);
	}
	while(l<r&&onright(q[l],p[r]))r--;
	while(l<r&&onright(q[r],p[l+1]))l++;
	if(r-l<=1)return false;
	res=isLL(q[l],q[r]);
	return true;
}
bool cmp(int a,int b)
{
	return sameDir(plane[a],plane[b])?plane[b].include(plane[a][0]):plane[a].dir().alpha()<plane[b].dir().alpha();
}
bool check(double r)
{
//	printf("check(%.12lf)\n",r);
	for(int i=1;i<=n;i++)plane[i+n]=Line(p[i%n+1],p[i]).push(r);
	for(int i=1;i<=2*n;i++)sa[i]=i;
	sort(sa+1,sa+2*n+1,cmp);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		if(now==i)now=now%n+1;
//		printf("(%d,%d) ",i,now);
		while(now!=i&&HalfPlane(i,now,ans[i]))now=now%n+1;
		maxr[i]=now;
//		printf("%d ",maxr[i]);
	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		int j=maxr[i];
		if(maxr[j]>j&&(i>=j&&i<=maxr[j]))return 1;
		if(maxr[j]<=j&&(i>=j||i<=maxr[j]))return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	if(n<=4)
	{
		printf("0\n");
		printf("%.12lf %.12lf\n",p[1].x,p[1].y);
		printf("%.12lf %.12lf\n",p[3].x,p[3].y);
		return 0;
	}
	for(int i=1;i<=n;i++)plane[i]=Line(p[i],p[i%n+1]);
	double l=1e-4,r=1e4;
	for(int i=1;i<=40;i++)
	{
		double m=sqrt(l*r);
		if(check(m))r=m;
		else l=m;
	}
	check(r);
	printf("%.12lf\n",sqrt(l*r));
	for(int i=1;i<=n;i++)
	{
		int j=maxr[i];
		if(maxr[j]>j&&(i>=j&&i<=maxr[j]))
		{
			printf("%.12lf %.12lf\n",ans[i].x,ans[i].y);
			printf("%.12lf %.12lf\n",ans[j].x,ans[j].y);
			return 0;
		}
		if(maxr[j]<=j&&(i>=j||i<=maxr[j]))
		{
			printf("%.12lf %.12lf\n",ans[i].x,ans[i].y);
			printf("%.12lf %.12lf\n",ans[j].x,ans[j].y);
			return 0;
		}
	}
	return 0;
}