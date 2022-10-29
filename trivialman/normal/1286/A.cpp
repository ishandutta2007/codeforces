#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 105;
 
int n, a[N], dp[N][N][2];
 
int main(){
	cin>>n;
	rep(i,1,n) cin>>a[i];
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0] = dp[0][0][1] = 0;
	rep(i,1,n) rep(j,0,i){
		if(a[i]%2 || !a[i]) dp[i][j][1] = min(dp[i-1][j][0]+1, dp[i-1][j][1]);
		if(a[i]%2==0 && j) dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]+1);
	}
	cout<<min(dp[n][n/2][0], dp[n][n/2][1]);
	return 0;
}