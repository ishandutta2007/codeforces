#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
	int id;
	Point(ll xx=0,ll yy=0,int idd=0){x=xx,y=yy,id=idd;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	ll dot(Point p){return x*p.x+y*p.y;}
	ll det(Point p){return x*p.y-y*p.x;}
};
Point a[2005],b[2005];
int n,p[2005],in[2005],x[4005],y[4005],tot;
bool cmp(Point x,Point y)
{
	return x.det(y)>0;
}
int find(int x)
{
	return in[x]==x?x:in[x]=find(in[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].id=i;
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p[i]||in[i])continue;
		in[i]=i;
		int j=p[i];
		while(j!=i)
		{
			in[j]=i;
			j=p[j];
		}
	}
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]!=i&&(st==0||(a[i].x<a[st].x||(a[i].x==a[st].x&&a[i].y<a[st].y))))
		  st=i;
	}
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=st&&p[i]!=i)
		{
			b[++top]=a[i]-a[st];
			b[top].id=i;
		}
	}
	sort(b+1,b+top+1,cmp);
	for(int i=1;i<top;i++)
	{
		if(find(b[i].id)!=find(b[i+1].id))
		{
			tot++;
			x[tot]=b[i].id;
			y[tot]=b[i+1].id;
			swap(p[b[i].id],p[b[i+1].id]);
			in[find(b[i].id)]=find(b[i+1].id);
		}
	}
	while(p[st]!=st)
	{
		tot++;
		x[tot]=st;
		y[tot]=p[st];
		swap(p[st],p[p[st]]);
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d %d\n",x[i],y[i]);
	return 0;
}