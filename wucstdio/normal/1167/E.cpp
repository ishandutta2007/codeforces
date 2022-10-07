#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,a[1000005],l[1000005],r[1000005],maxv[1000005],val[1000005],pos1,posn;
ll ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)l[i]=n+1;
	for(int i=1;i<=n;i++)
	{
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
		maxv[i]=max(maxv[i-1],a[i]);
	}
	for(int i=1;i<=m;i++)val[i]=max(max(maxv[r[i]],i),val[i-1]);
	int nowr=0;
	for(int i=1;i<=m;i++)
	{
		if(l[i]<nowr)
		{
			pos1=i-1;
			break;
		}
		else nowr=max(nowr,r[i]);
	}
	if(!pos1)pos1=m;
	int nowl=n+1;
	for(int i=m;i>=1;i--)
	{
		if(r[i]>nowl)
		{
			posn=i+1;
			break;
		}
		else nowl=min(nowl,l[i]);
	}
	if(!posn)posn=1;
	for(int i=1;i-1<=pos1;i++)
	{
		int p=max(posn-1,val[i-1]);
		p=max(p,i);
		ans+=m-p+1;
	}
	printf("%I64d\n",ans);
	return 0;
}