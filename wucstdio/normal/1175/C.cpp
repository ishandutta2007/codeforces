#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Data
{
	int p;
	bool flag;
}c[400005];
int t,n,a[200005],k;
bool cmp(Data a,Data b)
{
	return a.p<b.p||(a.p==b.p&&a.flag>b.flag);
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		c[2*i-1].p=a[i]-x;
		c[2*i-1].flag=1;
		c[2*i].p=a[i]+x;
		c[2*i].flag=0;
	}
	sort(c+1,c+2*n+1,cmp);
	int now=0;
	for(int i=1;i<=2*n;i++)
	{
		if(c[i].flag)now++;
		else now--;
		if(now>k)return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int l=0,r=1000000000;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		check(l);
		int now=0;
		for(int i=1;i<=2*n;i++)
		{
			if(c[i].flag>0)now++;
			else now--;
			if(now>k)
			{
				printf("%d\n",c[i].p);
				break;
			}
		}
	}
	return 0;
}