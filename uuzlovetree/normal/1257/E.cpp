#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int k1,k2,k3,n;
int dp[maxn][3],bel[maxn];
int main()
{
	scanf("%d%d%d",&k1,&k2,&k3);
	for(int x,i=1;i<=k1;++i)
	{
		scanf("%d",&x);
		bel[x]=0; 
	} 
	for(int x,i=1;i<=k2;++i)
	{
		scanf("%d",&x);
		bel[x]=1; 
	} 
	for(int x,i=1;i<=k3;++i)
	{
		scanf("%d",&x);
		bel[x]=2; 
	} 
	n=k1+k2+k3;
	memset(dp,127/2,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
		{
			for(int k=j;k<3;++k)
			{
				dp[i+1][k]=min(dp[i+1][k],dp[i][j]+((bel[i+1]==k)?0:1));
			}
		}
	}
	cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<endl;
}