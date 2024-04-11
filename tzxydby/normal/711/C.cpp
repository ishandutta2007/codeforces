#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long n,m,b,ans=inf,dp[101][101][101],col[101],dis[101][101];
int main()
{
	ios::sync_with_stdio(false);
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>m>>b;
	for(int i=1;i<=m;i++)
		dp[0][0][i]=0;
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>dis[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			for(int k=(col[i]?col[i]:1);k<=(col[i]?col[i]:m);k++)
				for(int l=(col[i-1]?col[i-1]:1);l<=(col[i-1]?col[i-1]:m);l++)
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-(k!=l||i==1)][l]+(col[i]?0:dis[i][k]));
	for(int i=1;i<=m;i++)
		ans=min(ans,dp[n][b][i]);
	cout<<(ans==inf?-1:ans);
	return 0;
}