//  Created by Zhikun on 2018/10/3.
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
char S[2020];
ll mod = 1e9+7;
ll n,k,tr[2020],dp[1020][1020][2] = {0},ans = 0,qzh[2020] = {0};

int main() {
	//cout<<2<<endl;
	cin>>S;
	n = strlen(S);
	//cout<<n<<endl;
	cin>>k;
	if(k == 0){
	cout<<1<<endl;
	return 0;
	}
	tr[1] = 0;
	for(int i=2;i<2020;i++)tr[i] = tr[__builtin_popcount(i)]+1;
	dp[0][0][1] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0][0] = dp[i-1][0][0];
		if(S[i-1] == '0')dp[i][0][1] = dp[i-1][0][1];
		if(S[i-1] == '1')dp[i][0][0] = dp[i-1][0][0]+dp[i-1][0][1];
		//cout<<i<<' '<<0<<' '<<dp[i][0][0]+dp[i][0][1]<<endl;
		for(int j=1;j<=i;j++){
			if(S[i-1] == '0'){
				dp[i][j][0] = (dp[i-1][j-1][0]+dp[i-1][j][0])%mod;
				dp[i][j][1] = dp[i-1][j][1];
			}else{
				dp[i][j][0] = (dp[i-1][j-1][0]+dp[i-1][j][0]+dp[i-1][j][1])%mod;
				dp[i][j][1] = dp[i-1][j-1][1];
			}
			//cout<<i<<' '<<j<<' '<<dp[i][j][0]+dp[i][j][1]<<endl;
		}
	}
	//cout<<n<<endl;
	for(int i=1;i<1010;i++){
		if(tr[i] == k-1 && i<=n){
		//cout<<i<<' '<<n<<endl;
		ans=(ans+dp[n][i][0]+dp[n][i][1])%mod;
		}
	}
	//cout<<ans<<endl;
	if(k == 1)ans-=1;
	cout<<ans%mod<<endl;
	//cout<<233<<endl;
	return 0;
}