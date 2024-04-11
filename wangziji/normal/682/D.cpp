#include <iostream>
using namespace std;
int dp[1005][1005][12][2];//dp[i][j][k][0/1]i,jk 
int main(int argc, char** argv) {
	int n,m,t;
	cin >> n >> m >> t;
	string a,b;
	cin >> a >> b;
	a=' '+a,b=' '+b;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=t;k++)
				for(int l=0;l<=1;l++)
					dp[i][j][k][l]=-1e9;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=t;k++)
				dp[i][j][k][1]=-1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=t;k>=0;k--)
			{
				if(a[i]==b[j])
				{
					dp[i][j][k][1]=max(dp[i][j][k][1],dp[i-1][j-1][k][1]+1);
			//		cout << i << " "<< j << "\n";
				}
				if(a[i]==b[j]&&k)
				{
					dp[i][j][k][1]=max(dp[i][j][k][1],dp[i-1][j-1][k-1][0]+1);
			//		cout << i << " " << j << "\n";
				}
				dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j][k][1]);
				dp[i][j][k][0]=max(dp[i][j][k][0],dp[i-1][j][k][0]);
				dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j-1][k][0]);
				dp[i][j][k][0]=max(dp[i][j][k][0],dp[i-1][j][k][1]);
				dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j-1][k][1]);
			}
			ans=max(ans,dp[i][j][t][0]);
	//		if(dp[i][j][t][0]>3) cout << i << ' ' << j << "\n";
		}
	}
	cout << ans;
	return 0;
}