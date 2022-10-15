// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=100007;
const int K=207;
mt19937 rng(time(NULL));
int n,k;
vi g[N];
int dp[N][K],sz[N],f[K],C[K][K];
int sub;
void dfs(int u,int p){
    bool ok=0;
    // sz[u]=1;
    for (auto c:g[u]){
        if (c==p) continue;
        dfs(c,u);
        // sz[u]+=sz[c];
        if (!ok) {
            rep(i,k+1) dp[u][i]=dp[c][i];
            ok=1;
        } 
        else{
            vi f(min(sz[u]+sz[c],k)+1,0);
            for (int i=0;i<=min(sz[u],k);++i){
                for (int j=0;j<=min(sz[c],k)&&i+j<=k;++j){
                    f[i+j]=(f[i+j]+dp[c][j]*dp[u][i])%mod;
                }
            }
            for (int i=0;i<=min(sz[u]+sz[c],k);++i) dp[u][i]=f[i];
        }
        sz[u]+=sz[c];
    }
    if (!ok){dp[u][0]=2, dp[u][1]=1, sub=(sub+1)%mod;}
    else{
        for (int i=0;i<=k;++i) dp[u][i]=dp[u][i]*2%mod;
        if (u!=p){
            for (int i=0;i<k;++i) sub=(sub+(dp[u][i]-(i?0:1))*f[i+1])%mod;
            for (int i=k;i>0;--i) dp[u][i]=(dp[u][i]+dp[u][i-1])%mod;
            dp[u][1]=(dp[u][1]-1+mod)%mod;
        } 
    }
    sz[u]++;
    // cerr<<u<<": ";
    // rep(i,k+1) cerr<<dp[u][i]<<" ";
    // cerr<<endl;
}

int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>k;
    C[0][0]=1;
    for (int i=1;i<K;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for (int i=1;i<=k;++i){
        f[i]=modpow(i,k);
        for (int j=1;j<i;++j){
            f[i]=(f[i]-C[i][j]*f[j]%mod+mod)%mod;
        }
    }
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(0,0);
    int ans=0;
    for (int i=1;i<=k;++i){
        ans=(ans+dp[0][i]*f[i])%mod;
    }
    cout<<(ans-sub+mod)%mod;
    return 0;
}


/*
5 3
1 2
2 3
3 4
4 5


*/