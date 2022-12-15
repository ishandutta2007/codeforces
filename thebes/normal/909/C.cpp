#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char p='a', x; ll dp[5005]={1}, N, i, j, flag, s;
const int mod = 1e9+7;

int main(){
	for(scanf("%lld",&N),i=0;i<N;i++){
		scanf(" %c",&x);
		if(flag && p == 's'){
			for(s=0,j=5002;j>=0;j--){
				dp[j] = (dp[j]+s)%mod;
				s = dp[j];
			}
		}
		if(x == 'f'){
			for(j=5002;j>0;j--)
				dp[j] = dp[j-1];
			dp[0]=0; flag=1;
		}
		p = x;
	}
	ll ans = 0;
	for(i=0;i<=5002;i++)
		ans = (ans+dp[i])%mod;
	printf("%lld\n",ans);
	return 0;
}