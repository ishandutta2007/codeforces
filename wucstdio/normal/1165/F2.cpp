#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Sale
{
	int t;
	int d;
}a[2000005];
int n,m,k[2000005],rest[2000005],sum,last[2000005],sa[2000005],c[2000005];
bool cmp(Sale a,Sale b)
{
	return a.d<b.d;
}
bool check(int t)
{
	for(int i=1;i<=n;i++)last[i]=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i].d>t)break;
		last[a[i].t]=a[i].d;
	}
	for(int i=0;i<=t;i++)c[i]=0;
	for(int i=1;i<=n;i++)c[last[i]]++,rest[i]=k[i];
	for(int i=1;i<=t;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[last[i]]--]=i;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		int x=sa[i];
		if(last[x]==0)continue;
		int d=min(last[x]-num,rest[x]);
		num+=d;
		rest[x]-=d;
	}
	return 2*sum-num<=t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		sum+=k[i];
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].d,&a[i].t);
	sort(a+1,a+m+1,cmp);
	int l=sum,r=2*sum;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}