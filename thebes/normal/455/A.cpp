#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll cnt[MN], dp[MN][2], N, i;

int main(){
	for(scanf("%lld",&N);i<N;i++){
		ll x; scanf("%lld",&x);
		cnt[x] ++ ;
	}
	dp[1][1]=cnt[1]; dp[2][1]=2*cnt[2]; dp[2][0]=dp[1][1];
	for(i=3;i<=100000;i++){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = i*cnt[i]+dp[i-1][0];
	}
	printf("%lld\n",max(dp[100000][0],dp[100000][1]));
	return 0;
}