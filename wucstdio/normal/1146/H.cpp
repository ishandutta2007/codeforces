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
	Point operator/(ll d){return Point(x/d,y/d);}
	ll dot(Point p){return x*p.x+y*p.y;}
	ll det(Point p){return x*p.y-y*p.x;}
	double alpha(){return atan2(y,x);}
}p[305],a[305];
int n,m;
ll f[6][305][305];
bool cmp(Point a,Point b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool cmp2(Point a,Point b)
{
	return a.alpha()>b.alpha();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	ll ans=0;
	for(int st=1;st<=n;st++)
	{
		memset(f,0,sizeof(f));
		m=0;
		for(int i=st;i<=n;i++)
			a[++m]=p[i]-p[st];
		sort(a+2,a+m+1,cmp2);
		for(int i=2;i<=m;i++)
		  f[1][i][1]=1;
		for(int num=1;num<=3;num++)
		{
			for(int i=num+1;i<=n;i++)
			for(int j=1;j<i;j++)
			{
				if(!f[num][i][j])continue;
				for(int k=i+1;k<=m;k++)
				{
					if((a[i]-a[j]).det(a[k]-a[j])<0)
					  f[num+1][k][i]+=f[num][i][j];
				}
			}
		}
		for(int i=1;i<=m;i++)
		  for(int j=1;j<i;j++)
		    if((a[i]-a[j]).det(a[1]-a[j])<0)
		      ans+=f[4][i][j];
	}
	printf("%I64d\n",ans);
	return 0;
}