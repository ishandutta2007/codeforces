#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int dp[2005][2005][4];
signed main(){
	int n,k;cin>>n>>k;
	dp[1][2][0]=1;dp[1][1][1]=1;dp[1][1][2]=1;dp[1][2][3]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++){
			dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j-2][3])%MOD;
			dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j-1][2]+dp[i-1][j][3])%MOD;
			dp[i][j][2]=(dp[i-1][j][0]+dp[i-1][j-1][1]+dp[i-1][j][2]+dp[i-1][j][3])%MOD;
			dp[i][j][3]=(dp[i-1][j-2][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j][3])%MOD;
		}
	cout<<(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%MOD<<endl;
	return 0;
}