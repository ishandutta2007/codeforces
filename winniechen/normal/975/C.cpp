#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N 200005
#define ll long long
ll a[N],sum[N],k[N];
int n,m;
int find(ll x)
{
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(sum[mid]>x)r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d",&k[i]);
	}
	ll last=0;
	for(int i=1;i<=m;i++)
	{
		if(last+k[i]>=sum[n])
		{
			printf("%d\n",n);
			last=0;
		}else
		{
			last+=k[i];
			printf("%d\n",n-find(last)+1);
		}
	}
	return 0;
}