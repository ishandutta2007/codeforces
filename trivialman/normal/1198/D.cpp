#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 55;

int n,dp[N][N][N][N];
char s[N][N];

int dfs(int l,int u,int r,int d){
	if(~dp[l][u][r][d])return dp[l][u][r][d];
	if(l==r&&u==d)return s[l][u]=='#';
	
	int res = max(r-l,d-u)+1;
	// if partitioning into 2 sub-rectangles is not possible, total cost of rectangles must > max(r-l,d-u)+1.
	if(r-l>d-u)	rep(i,l,r-1) res = min(res, dfs(l,u,i,d) + dfs(i+1,u,r,d));
	else rep(i,u,d-1) res = min(res, dfs(l,u,r,i) + dfs(l,i+1,r,d));
	return dp[l][u][r][d] = res;
}

int main(){
	cin>>n;
	rep(i,0,n-1)cin>>s[i];
	memset(dp,-1,sizeof dp);
	cout<<dfs(0,0,n-1,n-1)<<endl;
	return 0;
}