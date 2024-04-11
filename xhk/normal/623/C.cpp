#include<bits/stdc++.h>
using namespace std;

struct point
{int x,y;
};
struct point a[100010];

int n,inf=1e9;
int minsy[100010],maxsy[100010];
long long ans;

bool cmp(point p1,point p2)
{return p1.x<p2.x;
}

long long sqr(long long x)
{return (long long)x*x;
}

int check(long long k)
{int i,j,j1,j2,flag,minpy=inf,maxpy=-inf;
 
 minsy[n+1]=inf;
 maxsy[n+1]=-inf;
 for(i=n;i>=1;i--)
 {	minsy[i]=min(minsy[i+1],a[i].y);
 	maxsy[i]=max(maxsy[i+1],a[i].y);
 }
 j=1;
 j1=n;
 for(i=1;a[i].x<=0 && i<=n;i++)
 {	while(j+1<=n && sqr(a[j+1].x-a[i].x)<=k) j++;
 	while(j1>i && a[j1].x>(-a[i].x)) j1--;
 	j2=min(j,j1);
	if(i==1 && j2==n) return 1;
	flag=1;
	if(sqr(max(maxsy[j2+1],maxpy)-min(minsy[j2+1],minpy))>k) flag=0;
	if(max((i>1?max(sqr(maxpy),sqr(minpy)):0),(j2<n?max(sqr(maxsy[j2+1]),sqr(minsy[j2+1])):0))+sqr(a[i].x)>k) flag=0;
	if(flag) return 1;
 	minpy=min(minpy,a[i].y);
 	maxpy=max(maxpy,a[i].y);
 }
 return 0;
}
 	

int main()
{int i,j,flag,minx=inf,miny=inf,maxx=-inf,maxy=-inf;
 long long l,r,mid;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {	scanf("%d%d",&a[i].x,&a[i].y);
 	minx=min(minx,a[i].x);
 	maxx=max(maxx,a[i].x);
 	miny=min(miny,a[i].y);
 	maxy=max(maxy,a[i].y);
 }
 ans=min(sqr(maxx-minx),sqr(maxy-miny));
 sort(a+1,a+n+1,cmp);
 l=0;
 r=1e17;
 while(l<=r)
 {	mid=(l+r)/2;
 	flag=0;
 	if(check(mid)) flag=1;
 	if(!flag)
 	{	for(i=1;i<=n/2;i++) swap(a[i],a[n+1-i]);
 		for(i=1;i<=n;i++) a[i].x=-a[i].x;
 		flag=check(mid);
 		for(i=1;i<=n;i++) a[i].x=-a[i].x;
 		for(i=1;i<=n/2;i++) swap(a[i],a[n+1-i]);
 	}
	if(flag)
 	{	ans=min(ans,mid);
 		r=mid-1;
 	}
 	else
 		l=mid+1;
 }
 printf("%I64d\n",ans);
 return 0;
}