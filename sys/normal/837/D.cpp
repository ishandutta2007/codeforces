#include <bits/stdc++.h>
using namespace std;
const int Maxn=205;
int maxi,n,k,cnt[Maxn][3],dp[205][12005],ans;
long long a[Maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&a[i]);
		x=a[i];
		while(x%2==0)
			cnt[i][1]++,x/=2;
		while(x%5==0)
			cnt[i][2]++,x/=5;
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int q=min(i,k);q>=1;q--)
			for(int j=maxi;j>=0;j--)
				dp[q][j+cnt[i][1]]=max(dp[q][j+cnt[i][1]],dp[q-1][j]+cnt[i][2]);
		maxi+=cnt[i][1];
	}
	for(int i=1;i<=12000;i++)
		ans=max(ans,min(i,dp[k][i]));
	printf("%d",ans);
	return 0;
}