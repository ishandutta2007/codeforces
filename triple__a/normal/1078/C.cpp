#include<bits/stdc++.h>
#define int long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
#define debug cout<<"potxdy"<<endl; 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=300007;
const int mod=998244353;

int n,dp[maxn][3]; // 0 not occupied; 1 parent, 2 child
VI vec[maxn];

int mult(int u,int v){
    return 1ll*u*v%mod;
}

void dfs(int u,int p){
    dp[u][0]=dp[u][1]=1;
    for (auto c:vec[u]){
        if (c==p) continue;
        dfs(c,u);
        int g[3];
        g[0]=mult(dp[u][0],dp[c][0]+dp[c][2]);
        g[1]=mult(dp[u][1],(dp[c][0]+2ll*dp[c][2])%mod);
        g[2]=(mult(dp[c][1],dp[u][1])+mult(dp[u][2],(dp[c][0]+2ll*dp[c][2])))%mod;
        dp[u][0]=g[0], dp[u][1]=g[1], dp[u][2]=g[2];
    }
}

#undef int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        vec[u].pb(v), vec[v].pb(u);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][2])%mod<<endl;
    return 0;
}