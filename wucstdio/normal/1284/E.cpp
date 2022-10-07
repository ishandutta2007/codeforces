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
	ll dot(Point p){return x*p.x+y*p.y;}
	ll det(Point p){return x*p.y-y*p.x;}
	int quad()
	{
		if(x<=0&&y<0)return 0;
		if(x>0&&y<=0)return 1;
		if(x>=0&&y>0)return 2;
		return 3;
	}
}a[2505],b[2505];
int n,top;
ll ans;
bool cmp(Point a,Point b)
{
	if(a.quad()==b.quad())return a.det(b)>0;
	return a.quad()<b.quad();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			b[++top]=a[j]-a[i];
		}
		sort(b+1,b+top+1,cmp);
		int nowj=2;
		ll num=0;
		for(int i=1;i<n;i++)
		{
			if(nowj==i)nowj=i%(n-1)+1;
			while(nowj!=i&&b[i].det(b[nowj])>0)nowj=nowj%(n-1)+1;
			ll x=nowj>i?nowj-i-1:nowj+n-1-i-1;
			num+=x*(x-1)/2;
		}
		num=1ll*(n-1)*(n-2)*(n-3)/6-num;
		ans+=num;
	}
	printf("%lld\n",ans*(n-4)/2);
	return 0;
}