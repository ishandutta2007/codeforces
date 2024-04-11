#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
long long sum[max_n];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			sum[i]=sum[i-1]+a[i];
		long long mx=-1e18;
		for(int i=1;i<=n-1;++i)
		{
			long long k=sum[n]+1ll*(n-i)*a[1]+1ll*i*a[n]-a[1]-a[n];
			long long b=(sum[n]-sum[i])*a[1]+sum[i]*a[n]-1ll*a[1]*a[n];
			int L=-a[i+1],R=-a[i];
			mx=max(mx,k*L+b),mx=max(mx,k*R+b);
		}
		long long k1=sum[n]-sum[1]+(n-1ll)*a[1];
		long long b1=(sum[n]-sum[1])*a[1];
		if(k1>0)
		{
			puts("INF");
			continue;
		}
		mx=max(mx,k1*(-a[1])+b1);
		long long k2=sum[n-1]+(n-1ll)*a[n];
		long long b2=sum[n-1]*a[n];
		if(k2<0)
		{
			puts("INF");
			continue;
		}
		mx=max(mx,k2*(-a[n])+b2);
		printf("%lld\n",mx);
	}
	return 0;
}