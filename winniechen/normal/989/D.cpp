#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 100005
struct node
{
	int l,r,v;
	friend bool operator<(const node &a,const node &b)
	{
		return a.l<b.l;
	}
}a[N],b[N];
int n,len,w;
int cnt1=0,cnt2=0;
long long ans=0;
int findb(double x)
{
	x=x+1e-8;
	int l=1,r=cnt2+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(b[m].r>x)r=m;
		else l=m+1;
	}
	return cnt2-l+1;
}
int finda(double x)
{
	x=x-1e-4;
	int l=1,r=cnt2+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(a[m].l<x)r=m;
		else l=m+1;
	}
	return l;
}
int main()
{
	scanf("%d%d%d",&n,&len,&w);
	for(int i=1;i<=n;i++)
	{
		int x,z;
		scanf("%d%d",&x,&z);
		if(z==1)
		{
			a[++cnt1].l=x,a[cnt1].r=x+len,a[cnt1].v=1;
		}else
		{
			b[++cnt2].l=x,b[cnt2].r=x+len,b[cnt2].v=-1;
		}
	}
	sort(a+1,a+cnt1+1);sort(b+1,b+cnt2+1);
	for(int i=1;i<=cnt1;i++)
	{
		if(a[i].l<0)
		{
			ans+=findb(((1.0*(w-1))/(1.0*(w+1)))*a[i].l);
		} 
		else
		{
			if(w<=1)continue;
			ans+=findb(((1.0*(w+1))/(1.0*(w-1)))*a[i].l);
		}
	}
	printf("%lld\n",ans);
	return 0;
}