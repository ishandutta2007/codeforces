#include<bits/stdc++.h>
#define ll long long
#define maxn 105
using namespace std;
const ll mod = 1000000007;
int n,k,d;
ll dp[maxn][maxn][2];
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	dp[0][0][0]=1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int l=1;l<=k;++l)if(j+l<=n)
			{
				if(l>=d)
				{
					dp[i+1][j+l][1]+=dp[i][j][0]+dp[i][j][1];
					dp[i+1][j+l][1]%=mod;
				}
				else
				{
					dp[i+1][j+l][0]+=dp[i][j][0];
					dp[i+1][j+l][0]%=mod;
					dp[i+1][j+l][1]+=dp[i][j][1];
					dp[i+1][j+l][1]%=mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=dp[i][n][1];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}