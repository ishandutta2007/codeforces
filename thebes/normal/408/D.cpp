#include <bits/stdc++.h>
using namespace std;

const int MN=1e3+3,mod=1e9+7;
int dp[MN], i, j, x, n, tot, ans;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x); tot=0; dp[i]=1;
		for(j=i;j>=x;j--) tot=(tot+dp[j])%mod;
		dp[i]=(dp[i]+tot)%mod;
		ans = (ans+dp[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}