#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct point
{
	double x,y;
}a[1005];
const double eps = 1e-10;
struct Line
{
	double k,b;
}L[1000005];
int cnt;
bool operator < (Line a,Line b)
{
	if(fabs(a.k-b.k)<eps)return a.b<b.b;
	return a.k<b.k;
}
bool operator == (Line a,Line b)
{
	return fabs(a.k-b.k)<eps&&fabs(a.b-b.b)<eps; 
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	cnt=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(a[i].x==a[j].x)
			{
				L[++cnt].k=10000000;
				L[cnt].b=a[i].x;
			}
			else
			{
				L[++cnt].k=(a[i].y-a[j].y)/(a[i].x-a[j].x);
				L[cnt].b=a[i].y-L[cnt].k*a[i].x;
			}
		}
	}
	sort(L+1,L+cnt+1);
	cnt=unique(L+1,L+cnt+1)-L-1;
	ll ans=0;
	ll num=1;
	for(int i=2;i<=cnt;++i)
	{
		if(fabs(L[i].k-L[i-1].k)>eps)
		{
			ans+=num*(1ll*cnt-num);
			num=0;
		}
		num++;
	}
	ans+=num*(1ll*cnt-num);
	cout<<ans/2<<endl;
	return 0;
}