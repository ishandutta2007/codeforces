#include <bits/stdc++.h>
using namespace std;

int dp[101][2], N, K, D;
int cmp(int s, int t){
	if(!s && t) return 1;
	if(dp[s][t] != -1) return dp[s][t];
	else dp[s][t] = 0;
	for(int i=1;i<=min(K,s);i++)
		dp[s][t] = (dp[s][t]+cmp(s-i,(t||(i>=D))))%1000000007;
	return dp[s][t];
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d",&N,&K,&D);
	printf("%d\n",cmp(N,0));
	return 0;
}