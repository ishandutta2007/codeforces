#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
long long dp[300005][10],n,m,pre,k,A[300005],INF=1e15,mx;
using namespace std;
int main(){
	cin>>n>>m>>k;
	REP(i,0,n)REP(j,0,m)dp[i][j]=-INF;
	REP(i,0,n)cin>>A[i],dp[i+1][1%m]=A[i]-k;
	dp[0][0]=0;
	REP(i,1,n+1) REP(j,0,m){
		pre=(j-1)%m;
		if(pre<0)pre+=m;
		dp[i][j]=max(dp[i][j],dp[i-1][pre]+A[i-1]-(pre?0:k));
		mx=max(mx,dp[i][j]);
	}
	cout<<mx;
	return 0;
}