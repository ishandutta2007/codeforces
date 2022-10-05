#include <bits/stdc++.h>
using namespace std;
const int Maxn=1<<15|5; 
const int p=1e9+7;
int n,T,dp[Maxn][4],t[Maxn],a[20],type[20],ans;
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&type[i]);
	int maxi=(1<<n)-1;
	for(int i=0;i<=maxi;i++)
	{
		for(int j=0;j<n;j++)
			if(i&(1<<j)) t[i]=t[i^(1<<j)]+a[j+1];
	}
	for(int i=1;i<=n;i++)
		dp[1<<(i-1)][type[i]]++;
	for(int i=0;i<=maxi;i++)
		for(int j=1;j<=3;j++)
			for(int k=0;k<n;k++)
				if(!(i&(1<<k))&&type[k+1]!=j)
					dp[i^(1<<k)][type[k+1]]=(dp[i^(1<<k)][type[k+1]]+dp[i][j])%p;
	for(int i=0;i<=maxi;i++)
		if(t[i]==T)
			ans+=((dp[i][1]+dp[i][2])%p+dp[i][3])%p,ans%=p;
	printf("%d",ans);
	return 0;
}