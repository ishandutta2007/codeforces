#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 5010;

int dp[N][N][2],c[N],n;

void dfs(int l, int r){
	if(l>=r){ dp[l][r][0] = dp[l][r][1] = 0; return;}
	if(dp[l][r][0]>=0) return;
	if(c[l]==c[r]){
		dfs(l+1, r-1);
		dp[l][r][0] = dp[l][r][1] = min(dp[l+1][r-1][0] + (c[l]!=c[l+1]), dp[l+1][r-1][1] + (c[r-1]!=c[r])); 
	}else{
		dfs(l+1, r);
		dfs(l, r-1);
		dp[l][r][0] = min(dp[l+1][r][0] + (c[l]!=c[l+1]), dp[l+1][r][1] + (c[l]!=c[r]));
		dp[l][r][1] = min(dp[l][r-1][0] + (c[l]!=c[r]), dp[l][r-1][1] + (c[r-1]!=c[r]));
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)cin>>c[i];
	memset(dp,-1,sizeof(dp));
	dfs(1,n);
	cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
	return 0;
}