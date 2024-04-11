#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define N 100005
int a[N],t[N],n;
long long sum[N],ans[N],num[N];
int find(long long x)
{
	int l=1,r=n+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(sum[m]<=x)
		{
			l=m+1;
		}else
		{
			r=m;
		}
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		sum[i]=sum[i-1]+(1ll*t[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int j=find(1ll*a[i]+sum[i-1]);
		if(j==n+1)
		{
			num[i]++;
			continue;
		}
		num[i]++,num[j]--;
		ans[j]+=(1ll*a[i]-sum[j-1]+sum[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		num[i]+=num[i-1];
		ans[i]+=(num[i]*t[i]);
	}
	for(int i=1;i<n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	printf("%I64d\n",ans[n]);
	return 0;
}