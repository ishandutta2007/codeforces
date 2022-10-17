#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct N
{
	int m,v,r;
	bool operator<(const N& b)const
	{
		return m==b.m?v<b.v:m<b.m;
	}
};
N a[100010];
bool check(int n,int k,int h,double T)
{
	int re=0;
	for(int i=0;i<n;i++)
	{
		if((double)(re+1)*h<=a[i].v*T)
		{
			re++;
			if(re>=k)
				break;
		}
	}
	return re>=k;
}
int main()
{
	int n,k,h;
	scanf("%d %d %d",&n,&k,&h);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].v);
	for(int i=0;i<n;i++)
		a[i].r=i+1;
	sort(a,a+n);
	double l=0;
	double r=1e10;
	int tim=100;
	while(tim--)
	{
		double mid=(l+r)/2.0;
		if(check(n,k,h,mid))
			r=mid;
		else
			l=mid;
	}
	int re=0;
	for(int i=0;i<n;i++)
	{
		if((double)(re+1)*h<=a[i].v*r)
		{
			re++;
			printf("%d ",a[i].r);
			if(re>=k)
				break;
		}
	}
	return 0;
}