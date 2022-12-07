#include<bits/stdc++.h>
using namespace std;
long long dp[300002][10],x,i,j,n,m,k,res;
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
	for (i=1;i<=n;res=max(res,dp[i][0]),i++)
		for (cin>>x,j=0;j<m;j++) dp[i][j]=max(0ll,x+(!j?-k:0)+dp[i-1][(j+m-1)%m]);
	printf("%lld",res);
}