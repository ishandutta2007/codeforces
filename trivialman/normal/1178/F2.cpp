#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int P = 998244353;
const int N = 1005;
 
int n, m, a[N*N], first[N], last[N], dp[N][N];
 
int dfs(int l,int r){
	if(dp[l][r]>=0)return dp[l][r];
	if(l>r) return 1;
	if(l==r) return (first[a[l]]==l && last[a[l]]==l) ? 1 : 0;
	int i1=l, i2;
	rep(i,l,r)if(a[i]<a[i1])i1=i;
	if(first[a[i1]]<l || last[a[i1]]>r) return dp[l][r] = 0;
	rep(i,l,r)if(a[i]==a[i1])i2=i;
	int totl=0, totr=0;
	rep(i,l,i1) totl = (totl + 1ll * dfs(l,i-1) * dfs(i,i1-1) ) % P;
	rep(i,i2,r) totr = (totr + 1ll * dfs(i2+1,i) * dfs(i+1,r) ) % P;
	dp[l][r] = 1ll * totl * totr % P;
	rep(i,i1+1,i2)if(a[i]==a[i1]){
		dp[l][r] = 1ll * dp[l][r] * dfs(i1+1,i-1) % P;
		i1 = i;
	}
	return dp[l][r];
}
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d",a+i);
	m = unique(a+1,a+m+1) - a - 1;
	if(m>2*n) return printf("0\n"),0;
	rep(i,1,m){
		if(!first[a[i]])first[a[i]]=i;
		last[a[i]]=i;
	}
	memset(dp,-1,sizeof dp);
	printf("%d\n",dfs(1,m));
	return 0;
}