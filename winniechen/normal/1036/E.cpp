#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 1005
#define eps 1e-8
#define ll long long
struct Point
{
	int x,y;
	bool operator < (const Point &a) const {return a.x==x?y<a.y:x<a.x;}
};
struct Segment{int a,b,c,d;long double k,B;}a[N];
int n,m;ll ans;
map<Point,int>mp;
bool check(long double x)
{
	long double y=round(x);
	return abs(y-x)<eps;
}
int check(int i,int x,int y)
{
	if(x>a[i].c||x<a[i].a||y<a[i].b||y>a[i].d)return 0;
	if(a[i].k==1e20)return 1;
	return abs(y-(a[i].k*x+a[i].B))<eps;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d);
		if(a[i].c==a[i].a)a[i].k=1e20,a[i].B=1e20;
		else a[i].k=((long double)a[i].d-a[i].b)/(a[i].c-a[i].a),a[i].B=a[i].b-a[i].a*a[i].k;
		//int tmp=__gcd(a[i].d-a[i].b,a[i].c-a[i].a);
		if(a[i].c!=a[i].a&&a[i].d!=a[i].b)
			ans+=__gcd(abs(a[i].d-a[i].b),abs(a[i].c-a[i].a));
		else ans+=abs(a[i].c-a[i].a)+abs(a[i].d-a[i].b);ans++;
		// printf("%lld\n",ans);
		if(a[i].a>a[i].c)swap(a[i].a,a[i].c);if(a[i].d<a[i].b)swap(a[i].b,a[i].d);
		// printf("%.3f %.3f\n",a[i].k,a[i].B);
	}//printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			long double x,y;
			if(a[i].k==1e20&&a[j].k==1e20)continue;
			if(a[j].k==1e20||a[i].k==1e20)
			{
				if(a[j].k==1e20)x=a[j].a,y=x*a[i].k+a[i].B;
				else x=a[i].a,y=a[j].k*x+a[j].B;
			}else x=(a[i].B-a[j].B)/(a[j].k-a[i].k),y=x*a[i].k+a[i].B;
			if(check(x)&&check(y))
			{
				int u=(int)round(x),v=(int)round(y);
				if(u<a[i].a||u>a[i].c||u<a[j].a||u>a[j].c||v<a[i].b||v>a[i].d||v<a[j].b||v>a[j].d)continue;
				if(mp.find((Point){u,v})==mp.end())
				{
					int num=0;
					for(int k=i+1;k<=n;k++)num+=check(k,u,v);
					ans-=num+1;mp[((Point){u,v})]=1;
					// printf("%d %d %.2f %.2f\n",i,j,x,y);
				}
			}
		}
	}printf("%lld\n",ans);
}