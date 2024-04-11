#include<cstdio>
#include<iostream>

using namespace std;

const long long inf=1ll<<55;

long long cost[330][330];
long long dp[330][330];

int main()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<330;i++) for(int j=0;j<330;j++) cost[i][j]=inf;
	for(int i=0;i<M;i++)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		l--;r--;
		for(int j=l;j<=r;j++) cost[j][r]=min(cost[j][r],(long long)c);
		for(int j=l;j<=r;j++) cost[l][j]=min(cost[l][j],(long long)c);
	}
	for(int i=0;i<330;i++) for(int j=0;j<330;j++) dp[i][j]=inf;
	for(int i=0;i<330;i++) dp[i][0]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<=i+1;j++)
		{
			long long res=inf;
			for(int k=0;k<i;k++) res=min(res,dp[k][j]);
			for(int k=1;k<=j;k++) res=min(res,dp[i-k][j-k]+cost[i-k+1][i]);
			if(j==i+1) res=min(res,cost[0][i]);
			dp[i][j]=min(dp[i][j],res);
		}
	}
	long long ans=dp[N-1][K]!=inf?dp[N-1][K]:-1;
	cout<<ans<<"\n";
	return 0;
}