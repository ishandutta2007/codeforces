#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
	Point(ll xx=0,ll yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	bool operator==(Point p){return x==p.x&&y==p.y;}
	ll det(Point p){return x*p.y-y*p.x;}
	Point unit()
	{
		if(x<0||(x==0&&y<0))x=-x,y=-y;
		ll d=__gcd(x,y);
		if(d<0)d=-d;
		return Point(x/d,y/d);
	}
}a[1005];
struct Line
{
	Point st,v;
	bool operator==(Line b)
	{
		return v==b.v&&(st==b.st||(st-b.st).unit()==v);
	}
}p[1000005];
ll n,top;
bool cmp(Line a,Line b)
{
	return a.v.x<b.v.x||(a.v.x==b.v.x&&a.v.y<b.v.y)||(a.v==b.v&&a.st.det(a.v)<b.st.det(b.v));
}
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		p[++top].v=a[i]-a[j];
		p[top].st=a[j];
		p[top].v=p[top].v.unit();
	}
	sort(p+1,p+top+1,cmp);
	for(int i=top;i>=2;i--)
	  if(p[i]==p[i-1])
		p[i].v=Point(2147483647,2147483647);
	sort(p+1,p+top+1,cmp);
	while(p[top].v.x==2147483647)top--;
	ll ans=0,num=0;
	for(int i=1;i<=top;i++)
	{
		if(p[i]==p[i-1])continue;
		if(p[i].v==p[i-1].v)num++;
		else
		{
			ans+=num*(num+1)/2;
			num=0;
		}
	}
	ans+=num*(num+1)/2;
	printf("%I64d\n",(top*top-top)/2-ans);
	return 0;
}