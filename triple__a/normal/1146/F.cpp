// how to come up with such solution :(

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
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=200007;
const int K=207;
mt19937 rng(time(NULL));

int n;
int p[N],dp[2][N];
vi g[N];
int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
void dfs(int u){
    if (sz(g[u])==0) {dp[0][u]=dp[1][u]=1; return;}
    vector<pii> res;
    for (auto c:g[u]){
        dfs(c);
        res.pb({dp[0][c],dp[1][c]});
    }
    int prod=1,n_prod=1,sum=0,nzero=0,idx=-1;
    rep(i,sz(res)){
        auto c=res[i];
        n_prod=n_prod*(c.F+c.S)%mod;
        if (c.F==0) nzero++, idx=i, prod=0;
        if (!nzero) {
            auto inv=[&](int u){
                return modpow(u,mod-2);
            };
            prod=prod*c.F%mod;
            sum=(sum+c.S*inv(c.F))%mod;
        }
    }
    int inv2=(mod+1)/2;
    int ssum=0;
    if (!nzero) ssum=sum*prod%mod;
    else {
        if (nzero>1) ssum=0;
        else {
            ssum=1;
            for (int j=0;j<sz(res);++j){
                auto c=res[j];
                if (j==idx) ssum=ssum*c.S%mod;
                else ssum=ssum*c.F%mod;
            }
        }
    }
    dp[0][u]=(n_prod-ssum+mod)%mod;
    dp[1][u]=(n_prod-prod+mod)%mod;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep1(i,n-1) cin>>p[i], p[i]--, g[p[i]].pb(i);
    dfs(0);
    cout<<dp[0][0]<<endl;
    return 0;
}


/*
5
1 1 1 1


*/