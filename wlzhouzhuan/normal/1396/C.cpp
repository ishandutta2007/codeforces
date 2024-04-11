#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,r1,r2,r3,d,a[1000001],dp[1000003];
signed main()
{
	scanf("%lld %lld %lld %lld %lld",&n,&r1,&r2,&r3,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		dp[i]=114514114514114514;
	}
	dp[n+1]=dp[n+2]=112414114514114514;
	dp[1]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+a[i]*r1+r3+d);
		dp[i+1]=min(dp[i+1],dp[i]+min((a[i]+1)*r1,r2)+r1+d*3);
		dp[i+2]=min(dp[i+2],dp[i]+min((a[i]+1)*r1,r2)+min((a[i+1]+1)*r1,r2)+2*r1+d*4); 
	}
	cout<<min(dp[n+1]-d,dp[n-1]+min((a[n-1]+1)*r1,r2)+r1*a[n]+r3+2*d+r1);
	return 0;
}