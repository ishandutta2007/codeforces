// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!

const int maxn=300007;
const int mod=998244353;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(vi x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t ret=0;
        for (auto c:x){
            ret^=splitmix64(c + FIXED_RANDOM);
        }
        return ret;
    }
};

unordered_set<vi,custom_hash> st;

int n,m,k;
int dp[maxn];
int cnt[maxn];
int vis[maxn];
vi res;
set<int> values[maxn];

int par[maxn],sz[maxn],dist[maxn],ban[maxn];

int fnd(int u){
    if (par[u]==u) return u;
    int ret=fnd(par[u]);
    dist[u]+=dist[par[u]];
    return par[u]=ret;
}
void unite(int u,int v,int d){
    int pu=fnd(u), pv=fnd(v);
    // cerr<<u<<" "<<v<<" "<<pu<<" "<<pv<<" "<<dist[u]<<" "<<dist[v]<<" "<<d<<endl;
    if (pu!=pv) {
        par[pv]=pu, sz[pu]+=sz[pv], dist[pv]=dist[u]+d-dist[v];
    }
    else{
        if (d!=dist[v]-dist[u]) ban[u]=1;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    cin>>n>>m>>k;
    rep1(i,k) par[i]=i,sz[i]=1;
    rep(i,n){
        vi hii;
        hii.clear();
        int w;
        cin>>w;
        rep(i,w){
            int u;
            cin>>u;
            hii.pb(u);
        }
        st.insert(hii);
    }
    for (auto v:st){
        rep1(i,sz(v)-1) unite(v[0],v[i],i);
    }
    for (int i=1;i<=k;++i){
        if (ban[i]) {ban[fnd(i)]=1; continue;}
        if (values[fnd(i)].find(dist[i])!=values[fnd(i)].end()) ban[fnd(i)]=1;
        values[fnd(i)].insert(dist[i]);
    }
    for (int i=1;i<=k;++i){
        if (par[i]!=i) continue;
        if (ban[i]) continue;
        cnt[sz[i]]++;
    }
    for (int i=1;i<=m;++i){
        if (cnt[i]) res.pb(i);
    }
    dp[0]=1;
    for (int i=1;i<=m;++i){
        for (auto c:res){
            if (c>i) continue;
            dp[i]=(dp[i]+dp[i-c]*cnt[c])%mod;
        }
    }
    cout<<dp[m]<<"\n";
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/