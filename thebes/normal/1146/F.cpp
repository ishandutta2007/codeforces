#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5, mod = 998244353;
int dp[MN][2], n, i, x;
vector<int> adj[MN];

void solve(int n){
    int tmp = 1;
    for(auto v : adj[n]){
        solve(v);
        dp[n][0]=1LL*dp[n][0]*(dp[v][0]+dp[v][1])%mod;
        dp[n][0]=(dp[n][0]+1LL*dp[n][1]*dp[v][1])%mod;
        dp[n][1]=1LL*dp[n][1]*(dp[v][0])%mod;
        dp[n][1]=(dp[n][1]+1LL*tmp*(dp[v][1]))%mod;
        tmp = 1LL*tmp*(dp[v][0])%mod;
    }
    if(adj[n].empty()) dp[n][0]=dp[n][1]=1;
    else dp[n][1]=(dp[n][0]+dp[n][1])%mod, dp[n][0]=(1LL*tmp+dp[n][0])%mod;
}

int main(){
    for(scanf("%d",&n),i=2;i<=n;i++)
        scanf("%d",&x), adj[x].push_back(i);
    solve(1);
    printf("%d\n",dp[1][0]%mod);
    return 0;
}