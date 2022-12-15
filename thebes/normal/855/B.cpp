#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5;
ll dp[4][MN], N, a[4], i, j, arr[MN];

int main(){
	for(scanf("%lld%lld%lld%lld",&N,&a[1],&a[2],&a[3]),i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	for(j=1;j<=3;j++){
		dp[j][N+1] = -(1LL<<62);
		for(i=N;i>=1;i--)
			dp[j][i]=max(dp[j][i+1],a[4-j]*arr[i]+dp[j-1][i]);
	}
	printf("%lld\n",dp[3][1]);
	return 0;
}