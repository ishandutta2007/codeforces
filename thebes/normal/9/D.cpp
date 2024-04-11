#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[36][36], N, H, i, ans;
ll cmp(ll n,ll h){
	if(n==0&&h==0) return 1LL;
	else if(h>n||h<0) return 0LL;
	else if(dp[n][h]!=-1) return dp[n][h];
	dp[n][h] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<h-1;j++){
			dp[n][h]+=cmp(i-1,h-1)*cmp(n-i,j);
			dp[n][h]+=cmp(i-1,j)*cmp(n-i,h-1);
		}
		dp[n][h]+=cmp(i-1,h-1)*cmp(n-i,h-1);
	}
	return dp[n][h];
}

int main(){
	scanf("%lld%lld",&N,&H);
	memset(dp, -1, sizeof(dp));
	for(i=H;i<=N;i++) ans+=cmp(N,i);
	printf("%lld\n",ans);
	return 0;
}