#include <iostream>
using namespace std;
int dp[5005][5005],a[5005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
			dp[i][j]=1e9;
	}
	for(int i=0;i<=5000;i++) dp[0][i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			dp[i][min(j,a[i])]=min(dp[i][min(j,a[i])],dp[i-1][j]+(a[i]>j));
		}
		for(int j=1;j<=min(5000,a[i]);j++)
			dp[i][j]=min(dp[i][j],dp[i][j-1]+1-(a[i]==j));
	}
	int ans=1e9;
	for(int i=0;i<=5000;i++)
		ans=min(ans,dp[n][i]);
	cout << ans;
	return 0;
}