#include<bits/stdc++.h>
#define maxn 85
#define maxm 100005
using namespace std;
int n,m;
int X[maxn],S[maxn];
int dp[maxm][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&S[i]);
	for(int i=1;i<=n;++i)dp[1][i]=max(0,X[i]-S[i]-1);
	for(int i=2;i<=m;++i)
		for(int j=1;j<=n;++j)dp[i][j]=1000000000;
	for(int i=1;i<m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i+1<=X[j]+S[j])dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			else dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
			if(i<=X[j])dp[min(2*X[j]-i,m)][j]=min(dp[min(2*X[j]-i,m)][j],dp[i][j]);
			for(int k=1;k<=n;++k)if(k!=j&&i<=X[k])
			{
				if(X[k]-S[k]<=i)dp[i+1][k]=min(dp[i+1][k],dp[i][j]);
				else dp[i+1][k]=min(dp[i+1][k],dp[i][j]+X[k]-S[k]-(i+1));
			}
		}
	}
	int ans=1000000000;
	for(int i=1;i<=n;++i)ans=min(ans,dp[m][i]);
	cout<<ans<<endl;
}