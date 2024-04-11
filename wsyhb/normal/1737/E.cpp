#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv2=(mod+1)>>1;
const int max_n=1e6+5;
int dp[max_n],sum[max_n],Pow2[max_n],Pow[max_n],ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			puts("1");
			continue;
		}
		if(n==2)
		{
			puts("0");
			puts("1");
			continue;
		}
		Pow2[0]=Pow[0]=1;
		for(int i=1;i<=n;++i)
		{
			Pow2[i]=2*Pow2[i-1]%mod;
			Pow[i]=1ll*inv2*Pow[i-1]%mod;
		}
		dp[n]=sum[n]=1;
		for(int i=n-1;i>=2;--i)
		{
			int lim=max((i+1)/2-1,1);
			if(i-1<lim)
				continue;
			dp[i]=sum[i+1]-sum[min(i<<1,n+1)];
			dp[i]+=dp[i]<0?mod:0;
			if(i>n-i)
			{
				++dp[i];
				dp[i]-=dp[i]>=mod?mod:0;
			}
			if(lim<=i-2)
				ans[i]=1ll*dp[i]*Pow2[i-2-lim]%mod;
			else
				ans[i]=dp[i];
			sum[i]=sum[i+1]+dp[i];
			sum[i]-=sum[i]>=mod?mod:0;
		}
		int res=Pow2[n-1];
		for(int i=2;i<=n-1;++i)
		{
			res-=ans[i];
			res+=res<0?mod:0;
		}
		ans[n]=res;
		for(int i=1;i<=n;++i)
		{
//			fprintf(stderr,"i=%d ans[i]=%d dp[i]=%d\n",i,ans[i],dp[i]);
			printf("%lld\n",1ll*ans[i]*Pow[n-1]%mod);
		}
		for(int i=1;i<=n;++i)
			dp[i]=sum[i]=ans[i]=0;
	}
	return 0;
}