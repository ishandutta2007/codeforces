#include<bits/stdc++.h>

using namespace std;

int dp[107][107][2],n,a[107];

int main(){
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=dp[0][0][1]=0;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i){
		if (a[i]==0){
			for (int j=1;j<=n;++j){
				dp[i][j][0]=min(dp[i-1][j-1][1]+1,dp[i-1][j-1][0]);
			}
			for (int j=0;j<=n;++j){
				dp[i][j][1]=min(dp[i-1][j][1],dp[i-1][j][0]+1);
			}
			continue;
		}
		if (a[i]&1){
			for (int j=0;j<=n;++j){
				dp[i][j][1]=min(dp[i-1][j][1],dp[i-1][j][0]+1);
			}
		}
		else{
			for (int j=1;j<=n;++j){
				dp[i][j][0]=min(dp[i-1][j-1][1]+1,dp[i-1][j-1][0]);
			}
		}
	}
	cout<<min(dp[n][n/2][0],dp[n][n/2][1])<<endl;
	return 0;
}