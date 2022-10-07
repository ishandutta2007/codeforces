#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
	Point(ll xx=0,ll yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	Point operator*(ll d){return Point(x*d,y*d);}
	pair<double,double>operator/(double d){return make_pair((double)x/d,(double)y/d);}
	ll dot(Point p){return x*p.x+y*p.y;}
	ll det(Point p){return x*p.y-y*p.x;}
	Point rot90(){return Point(-y,x);}
	bool operator==(const Point p)const{return x==p.x&&y==p.y;};
}p[1000005],a[1000005];
int n,m,st[1000005],top,res[1000005],num;
bool cmp(Point a,Point b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
pair<double,double>isLL(Point p1,Point p2,Point q1,Point q2)
{
	ll a=(q1-p1).det(p2-p1);
	ll b=(p2-p1).det(q2-p1);
	return (q2*a+q1*b)/(double)(a+b);
}
pair<double,double>operator/(pair<double,double>a,int d)
{
	return make_pair(a.first/d,a.second/d);
}
double dis(Point p,pair<double,double>q)
{
	double x=(double)p.x,y=(double)p.y;
	return sqrt((x-q.first)*(x-q.first)+(y-q.second)*(y-q.second));
}
double calc(Point a,Point b,Point c)
{
	Point p1=a+b,p2=(b-a).rot90()+p1;
	Point q1=a+c,q2=(c-a).rot90()+q1;
	return dis(a,isLL(p1,p2,q1,q2)/2);
}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if(x-v>=0)p[++n]=Point(x-v,y);
		else
		{
			int d=v-x;
			p[++n]=Point(0,max(0,y-d));
			p[++n]=Point(0,min(100000,y+d));
		}
		if(x+v<=100000)p[++n]=Point(x+v,y);
		else
		{
			int d=v+x-100000;
			p[++n]=Point(100000,max(0,y-d));
			p[++n]=Point(100000,min(100000,y+d));
		}
		if(y-v>=0)p[++n]=Point(x,y-v);
		else
		{
			int d=v-y;
			p[++n]=Point(max(0,x-d),0);
			p[++n]=Point(min(100000,x+d),0);
		}
		if(y+v<=100000)p[++n]=Point(x,y+v);
		else
		{
			int d=v+y-100000;
			p[++n]=Point(max(0,x-d),100000);
			p[++n]=Point(min(100000,x+d),100000);
		}
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&p[i]==p[i-1])continue;
		while(top>=2&&(p[i]-p[st[top-1]]).det(p[i]-p[st[top]])<=0)top--;
		st[++top]=i;
	}
	for(int i=1;i<=top;i++)res[i]=st[i];
	num=top,top=0;
	for(int i=n;i>=1;i--)
	{
		if(i!=1&&p[i]==p[i-1])continue;
		while(top>=2&&(p[i]-p[st[top-1]]).det(p[i]-p[st[top]])<=0)top--;
		st[++top]=i;
	}
	for(int i=2;i<top;i++)res[++num]=st[i];
	for(int i=1;i<=num;i++)a[i]=p[res[i]];
	for(int i=1;i<=num;i++)p[i]=a[i];
	n=num;
	double ans=0;
	Point v1,v2,v3;
	for(int i=1;i<=num;i++)
	{
		double v=calc(p[i],p[i%num+1],p[(i+1)%num+1]);
		if(v>ans)
		{
			ans=v;
			v1=p[i],v2=p[i%num+1],v3=p[(i+1)%num+1];
		}
	}
	printf("%lld %lld\n%lld %lld\n%lld %lld\n",v1.x,v1.y,v2.x,v2.y,v3.x,v3.y);
	return 0;
}