#include <bits/stdc++.h>
using namespace std;
#define Maxn 600007
int n;
long long x,ans=0,sum0=0,sum1=0;
long long pre[Maxn];
int a[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		while (x!=0)
		{
			if (x%2==1) ++a[i];
			x/=2;
		}
		pre[i]=pre[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int mx=a[i];
		long long sum=a[i];
		for (int j=i-1;j>=max(1,i-120);j--)
		{
			mx=max(mx,a[j]);
			sum+=a[j];
			if (sum%2==0&&sum>=2LL*mx) ++ans;
		}
		if (pre[i]%2==0) ans+=sum0; else ans+=sum1;
		if (i-121>=0) 
		{
			if (pre[i-121]%2==0) ++sum0; else ++sum1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}