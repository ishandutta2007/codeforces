#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define eps 1e-8
struct node
{
	int x,y;
	// bool operator < (const node &a) const {return a.x==b.x?a.y<b.y:a.x<b.x;}
}a[N];
int n;
long double get_dis(const node &a,long double x,long double y){return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);}
int get(long double x,long double y)
{
	long double dis=y*y;
	for(int i=1;i<=n;i++)
		if(dis<get_dis(a[i],x,y)+eps)return 0;
	return 1;
}
long double check(long double x)
{
	long double l=0,r=1e14;
	for(int cas=0;cas<=100;cas++)
	{
		if(r-l<1e-7)return l;
		long double mid=(l+r)/2;
		if(get(x,mid))r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	scanf("%d",&n);int flag1=0,flag2=0;
	long double l=1e7,r=-1e7;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].y>0)flag1=1;if(a[i].y<0)flag2=1,a[i].y=-a[i].y;
		l=min((long double)a[i].x,l);r=max((long double)a[i].x,r);
	}
	if(flag1&&flag2)return puts("-1"),0;
	long double ans=check((l+r)/2);
	// printf("%.7f\n",(double)ans);
	for(int cas=0;cas<=60;cas++)
	{
		if(r-l<1e-7)break;
		long double mid1=(l+l+r)/3,mid2=(r+r+l)/3;
		if(check(mid1)>check(mid2))l=mid1;
		else r=mid2;
	}
	printf("%.7lf\n",(double)min(check(l),ans));
}
/*
2
10000000 1
-10000000 1
 */