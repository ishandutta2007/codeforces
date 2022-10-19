#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,rb,b,m,d,od[N],sq[N],t;
struct pt{int x,y,d;}r[N],a[N],v;
pt operator-(pt a,pt b){return {a.x-b.x,a.y-b.y};}
bool operator==(pt a,pt b){return 1ll*a.x*b.y==1ll*a.y*b.x;}
bool operator!=(pt a,pt b){return 1ll*a.x*b.y!=1ll*a.y*b.x;}
double dis(int p,int q){return sqrt(1ll*(a[p].x-a[q].x)*(a[p].x-a[q].x)+1ll*(a[p].y-a[q].y)*(a[p].y-a[q].y));}
double ans=1e18,sum;
int main()
{
	scanf("%d%d",&m,&rb);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&r[i].x,&r[i].y),r[i].d=i;
	sort(r+1,r+m+1,[&](pt a,pt b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
	for(int i=1;i<=m;i++)
	{
		if(i==1||r[i].x!=r[i-1].x||r[i].y!=r[i-1].y)
			a[++n]=r[i];
		if(r[i].d==rb)
			b=n;
	}
	if(n==1)
	{
		puts("0");
		return 0;
	}
	if(n==2)
	{
		printf("%.9lf\n",dis(1,2));
		return 0;
	}
	if(n==3)
	{
		if(b==1)
			printf("%.9lf\n",min(dis(1,2)+dis(2,3),dis(1,3)+dis(3,2)));
		if(b==2)	
			printf("%.9lf\n",min(dis(2,1)+dis(1,3),dis(2,3)+dis(3,1)));
		if(b==3)
			printf("%.9lf\n",min(dis(3,1)+dis(1,2),dis(3,2)+dis(2,1)));
		return 0;
	}
	pt d1=a[1]-a[2],d2=a[1]-a[3],d3=a[1]-a[4];
	if(d1==d2)
		v=d1;
	else if(d1==d3)
		v=d1;
	else
		v=d2,d=1;
	if(!d)
		for(int i=2;i<=n;i++)
			if((a[i]-a[1])!=v)
				d=i;
	for(int i=1;i<=n;i++)
		od[i]=i;
	sort(od+1,od+n+1,[&](int p,int q){return (a[p].x==a[q].x)?(a[p].y<a[q].y):(a[p].x<a[q].x);});
	if(!d)
		d=1;
	for(int i=1;i<=n;i++)
	{
		if(od[i]==b)
		{
			t=0,sum=0;
			if(od[i]==d)
			{
				for(int j=1;j<=n;j++)
					if(od[j]!=d)
						sq[++t]=od[j];
			}
			else
			{
				for(int j=i;j>=1;j--)
					if(od[j]!=d)
						sq[++t]=od[j];
				for(int j=i+1;j<=n;j++)
					if(od[j]!=d)
						sq[++t]=od[j];
			}
			for(int j=1;j<n-1;j++)
				sum+=dis(sq[j],sq[j+1]);
			if(od[i]!=d)
			{
				ans=min(ans,sum+dis(d,sq[n-1]));
				for(int j=1;j<n-1;j++)
					ans=min(ans,sum-dis(sq[j],sq[j+1])+dis(sq[j],d)+dis(sq[j+1],d));
			}
			else
				ans=min(ans,sum+dis(d,sq[1]));
			t=0;
			if(i==d)
			{
				for(int j=n;j>=1;j--)
					if(od[j]!=d)
						sq[++t]=od[j];
			}
			else
			{
				for(int j=i;j<=n;j++)
					if(od[j]!=d)
						sq[++t]=od[j];
				for(int j=i-1;j>=1;j--)
					if(od[j]!=d)
						sq[++t]=od[j];
			}
			sum=0;
			for(int j=1;j<n-1;j++)
				sum+=dis(sq[j],sq[j+1]);
			if(od[i]!=d)
			{
				ans=min(ans,sum+dis(d,sq[n-1]));
				for(int j=1;j<n-1;j++)
					ans=min(ans,sum-dis(sq[j],sq[j+1])+dis(sq[j],d)+dis(sq[j+1],d));
			}
			else
				ans=min(ans,sum+dis(d,sq[1]));
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}