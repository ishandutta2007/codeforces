#include <stdio.h>
#define int long long
using namespace std;
int mod =1e9+7,a[1005],n,ans=0,dp[1005][10005];

int abs(int a)
{
	if(a<0) return -a;
	return a;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) 
	{
		for(int j=0;j<10005;j++) dp[i][j]=(dp[i-1][j+a[i-1]] + dp[i-1][abs(j-a[i-1])]) %mod;
		dp[i][a[i-1]]+=1;
	}
	for(int i=1;i<=n;i++) ans=(ans+dp[i][0])%mod;
	printf("%lld",ans);
}