#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MN=1e3+4,mod=998244353;
ll dp[MN], N, i, arr[MN], j, c[MN][MN];

int main(){
	c[0][0]=1LL;
	for(i=1;i<MN;i++){
		c[i][0]=c[i][i]=1LL;
		for(j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	for(i=N;i>=1;i--){
		if(arr[i]>0&&arr[i]<MN){
			for(j=i+1;j<N;j++)
				dp[i]=(dp[i]+c[j-i][arr[i]]*dp[j+1])%mod;
			dp[i]=(dp[i]+c[N-i][arr[i]])%mod;
		}
	}
	ll ans = 0;
	for(i=1;i<N;i++)
		ans=(ans+dp[i])%mod;
	printf("%lld\n",ans);
	getchar(); getchar();
}