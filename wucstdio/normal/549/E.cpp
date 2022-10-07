#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double EPS=1e-9;
const double Pi=acos(-1.0);
struct Point
{
	double x,y;
	inline Point(double xx=0,double yy=0){x=xx,y=yy;}
	inline Point operator+(Point p){return Point(x+p.x,y+p.y);}
	inline Point operator-(Point p){return Point(x-p.x,y-p.y);}
	inline Point operator*(double d){return Point(x*d,y*d);}
	inline Point operator/(double d){return Point(x/d,y/d);}
	inline double dot(Point p){return x*p.x+y*p.y;}
	inline double det(Point p){return x*p.y-y*p.x;}
	inline double abs2(){return x*x+y*y;}
	inline double abs(){return sqrt(abs2());}
	inline Point rot90(){return Point(-y,x);}
}a[10005],b[10005],c[10005];
int n,m,st[10005],top;
inline bool cmp(Point a,Point b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
inline double dis(Point a,Point b)
{
	return (a-b).abs();
}
inline Point isLL(Point p1,Point p2,Point q1,Point q2)
{
	double a=(q1-p1).det(p2-p1);
	double b=(p2-p1).det(q2-p1);
	return (q2*a+q1*b)/(a+b);
}
inline Point circleCenter(Point a,Point b,Point c)
{
	Point p1=(a+b)/2,p2=p1+(b-a).rot90();
	Point q1=(a+c)/2,q2=q1+(c-a).rot90();
	return isLL(p1,p2,q1,q2);
}
void check(int x,int y,Point*a,int n)
{
	Point p1=c[x],p2=c[y];
	double l=-1e18,r=1e18;
	for(int i=1;i<=n;i++)
	{
		double v=(p2-p1).det(a[i]-p1);
		if(abs(v)<EPS)
		{
			if((p1-a[i]).dot(p2-a[i])<0)return;
			else continue;
		}
		Point o=circleCenter(p1,p2,a[i]);
		if(v<0)r=min(r,(o-p1).det(p2-p1));
		else l=max(l,(o-p1).det(p2-p1));
	}
	for(int i=1;i<=top;i++)
	{
		if(i==x||i==y)continue;
		double v=(p2-p1).det(c[i]-p1);
		if(abs(v)<EPS)continue;
		Point o=circleCenter(p1,p2,c[i]);
		if(v>0)r=min(r,(o-p1).det(p2-p1));
		else l=max(l,(o-p1).det(p2-p1));
	}
	if(l<r-EPS)
	{
		printf("YES\n");
		exit(0);
	}
}
void solve(int l,int r,Point*a,int n)
{
	check(l,r,a,n);
	if(r==l+1)return;
	Point o=(c[l]+c[r])/2+(c[r]-c[l]).rot90()*1000000000;
	double d=1e18;
	int k=0;
	for(int i=l+1;i<r;i++)
	{
		double v=dis(circleCenter(c[l],c[r],c[i]),o);
		if(v<d)d=v,k=i;
	}
	solve(l,k,a,n);
	solve(k,r,a,n);
}
void solve(Point*a,Point*b,int n,int m)
{
	sort(a+1,a+n+1,cmp);
	top=0;
	st[++top]=1;
	for(int i=2;i<=n;i++)
	{
		while(top>1&&(a[st[top]]-a[st[top-1]]).det(a[i]-a[st[top-1]])>=-0.1)top--;
		st[++top]=i;
	}
	int pre=top-1;
	for(int i=n-1;i>=1;i--)
	{
		while(top-pre>1&&(a[st[top]]-a[st[top-1]]).det(a[i]-a[st[top-1]])>=-0.1)top--;
		st[++top]=i;
	}
	top--;
	for(int i=1;i<=top;i++)c[i]=a[st[i]];
	solve(1,top,b,m);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1||m==1)return puts("YES"),0;
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++)scanf("%lf%lf",&b[i].x,&b[i].y);
	solve(a,b,n,m);
	solve(b,a,m,n);
	printf("NO\n");
	return 0;
}