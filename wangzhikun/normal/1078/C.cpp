#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll N = 300030;
ll mod = 998244353;
ll add(ll a,ll b){
	return a+b>=mod?a+b-mod:a+b;
}
ll mul(ll a,ll b){
	return 1ll*a*b%mod;
}
ll n,u,v,dp[N][3] = {0},ndp[N][3];
vector<ll> G[N];

void dfs(ll num,ll fa = -1){
	dp[num][0] = dp[num][1] = 0;
	dp[num][2] = 1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs(ct,num);
		ndp[num][1] = add(mul(add(dp[num][0],dp[num][2]),add(dp[ct][0],dp[ct][2])),mul(dp[num][1],add(mul(2,dp[ct][1]),dp[ct][2])));
		ndp[num][0] = add(mul(dp[num][2],dp[ct][1]),mul(dp[num][0],add(mul(2,dp[ct][1]),dp[ct][2])));
		ndp[num][2] = mul(dp[num][2],add(dp[ct][1],dp[ct][2]));
		for(ll i=0;i<3;i++)dp[num][i] = ndp[num][i];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	cout<<(dp[1][1]+dp[1][2])%mod<<endl;
	return 0;
}