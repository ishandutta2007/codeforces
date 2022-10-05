#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int t,k,dp[100004],sum[100004];
int main(){
	scanf("%d%d",&t,&k);
	dp[0]=1;
	for(int i=1;i<=100001;i++){
		if(i-k>=0)	dp[i]=(dp[i-1]+dp[i-k])%MOD;
		else		dp[i]=dp[i-1];
	}
	for(int i=1;i<=100001;i++)	sum[i]=(sum[i-1]+dp[i])%MOD;
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",(sum[b]-sum[a-1]+MOD)%MOD);
	}
}