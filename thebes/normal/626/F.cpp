#include <bits/stdc++.h>
using namespace std;

const int MN=202,mod=1e9+7;
typedef long long ll;
ll dp[2][MN][1005], N, K, arr[MN], i, j, k, ans;

int main(){
	for(scanf("%lld%lld",&N,&K),i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	sort(arr+1,arr+N+1);
	dp[1][0][0] = 1;
	for(i=1;i<=N;i++){
		memset(dp[(i+1)%2],0,sizeof(dp[(i+1)%2]));
		for(j=0;j<=N/2;j++){
			for(k=0;k<=K;k++){
				if(!dp[i%2][j][k]) continue;
				if(j*(arr[i]-arr[i-1])+k>K) continue;
				int tmp = j*(arr[i]-arr[i-1])+k;
				dp[(i+1)%2][j][tmp]=(dp[(i+1)%2][j][tmp]+(j+1)*dp[i%2][j][k])%mod;
				dp[(i+1)%2][j+1][tmp]=(dp[(i+1)%2][j+1][tmp]+dp[i%2][j][k])%mod;
				if(j) dp[(i+1)%2][j-1][tmp]=(dp[(i+1)%2][j-1][tmp]+j*dp[i%2][j][k])%mod;
			}
		}
	}
	for(i=0;i<=K;i++)
		ans=(ans+dp[(N+1)%2][0][i])%mod;
	printf("%lld\n",ans);
	return 0;
}