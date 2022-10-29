#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL P = 998244353;
const int N = 510;

int n, m, a[N], dp[N][N];

int dfs(int l,int r){
	if(dp[l][r])return dp[l][r];
	if(l>=r) return 1;
	int lowi = l;
	rep(i,l,r)if(a[i]<a[lowi])lowi=i;
	int totl=0, totr=0;
	rep(i,l,lowi) totl = (totl + 1ll * dfs(l,i-1) * dfs(i,lowi-1) ) % P;
	rep(i,lowi, r) totr = (totr + 1ll * dfs(lowi+1,i) * dfs(i+1,r) ) % P;
	return dp[l][r] = 1ll * totl * totr % P;
}

int main(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	cout<<dfs(1,n)<<endl;
	return 0;
}