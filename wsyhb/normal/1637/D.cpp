#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int a[max_n],b[max_n];
int R=1e4;
const int max_R=1e4+5;
bool dp[max_R],old[max_R];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
			scanf("%d",b+i);
		memset(dp,false,sizeof(dp));
		dp[0]=true;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=R;++j)
				old[j]=dp[j],dp[j]=false;
			for(int j=0;j<=R;++j)
			{
				if(old[j])
					dp[j+a[i]]=dp[j+b[i]]=true;
			}
		}
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=a[i]+b[i];
		long long ans=1e18;
		for(int i=0;i<=min(sum,(int)1e4);++i)
		{
			if(dp[i])
				ans=min(ans,1ll*i*i+1ll*(sum-i)*(sum-i));
		}
		for(int i=1;i<=n;++i)
			ans+=(n-2ll)*a[i]*a[i]+(n-2ll)*b[i]*b[i];
		printf("%lld\n",ans);
	}
	return 0;
}