#include<bits/stdc++.h>

using namespace std;

const int maxn = 10007;

int n,dp[maxn][7],u;

int main(){
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&u);
		dp[i][0]=dp[i-1][0]+(u==1);
		dp[i][1]=max(dp[i-1][1]+(u==2),dp[i-1][0]+1);
		dp[i][2]=max(dp[i-1][2]+(u==1),max(dp[i-1][1],dp[i-1][0])+1);
		dp[i][3]=max(dp[i-1][3]+(u==2),max(dp[i-1][2],max(dp[i-1][1],dp[i-1][0]))+1);
	}
	printf("%d\n",dp[n][3]);
	return 0;
}