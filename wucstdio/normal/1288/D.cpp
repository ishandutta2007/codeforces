#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[300005][8],v[300005],cnt[1005];
bool check(int x)
{
	for(int i=0;i<(1<<m);i++)cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		v[i]=0;
		for(int j=0;j<m;j++)
		  if(a[i][j]>=x)v[i]|=1<<j;
		cnt[v[i]]++;
	}
	for(int i=(1<<m)-1;i>=0;i--)
	  for(int j=0;j<m;j++)
	    if((1<<j)&i)cnt[(1<<j)^i]+=cnt[i];
	for(int i=1;i<=n;i++)
	  if(cnt[(1<<m)-1-v[i]])
	    return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=0;j<m;j++)
	    scanf("%d",&a[i][j]);
	int l=0,r=1000000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	check(r);
	for(int i=1;i<=n;i++)
	{
		if(cnt[(1<<m)-1-v[i]])
		{
			printf("%d ",i);
			for(int j=1;j<=n;j++)
			{
				if((v[i]|v[j])==(1<<m)-1)
				{
					printf("%d\n",j);
					return 0;
				}
			}
		}
	}
	return 0;
}