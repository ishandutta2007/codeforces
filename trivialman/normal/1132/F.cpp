#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 505;
 
char a[N];
int n,dp[N][N];

int dfs(int l,int r){
	if(l>r) return 0;
	if(dp[l][r]) return dp[l][r];
	dp[l][r] = dfs(l+1,r) + 1; 
	rep(i,l+1,r) if(a[i]==a[l]) dp[l][r] = min(dp[l][r], dfs(l+1,i-1) + dfs(i,r) );
	return dp[l][r];
}

int main(){
	cin>>n;
	cin>>(a+1);
	memset(dp,0,sizeof dp);
	dfs(1,n);
	cout<<dp[1][n]<<endl;
	return 0;
}