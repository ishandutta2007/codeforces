// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
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
 
 
const int maxn=500007;
const int mod=998244353;
const double pi=3.1415926535;
int n;
int a[maxn];
bool v[maxn];
vector<vi> chains;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n;
    rep1(i,n) cin>>a[i];
    rep1(i,n){
        if (v[i]) continue;
        int p=a[i];
        vi chain;
        chain.clear(), chain.pb(i);
        while (p!=i){
            chain.pb(p);
            p=a[p];
        }
        for (auto c:chain) v[c]=1;
        if (sz(chain)) chains.pb(chain);
    } 
    vector<pii> ans;
    ans.clear();
    int hii=-1;
    auto merge=[&](vi &l,vi &r){
        int pl=l[sz(l)-1], pr=r[sz(r)-1];
        ans.pb({pl,pr});
        rep(i,sz(l)-1) ans.pb({pr,l[i]});
        rep(i,sz(r)-1) ans.pb({pl,r[i]});
        ans.pb({pl,pr});
        hii=pl;
    };
    rep(i,sz(chains)/2){
        merge(chains[i<<1],chains[i<<1|1]);
    }
    if (sz(chains)&1){
        auto chain=chains[sz(chains)-1];
        if (sz(chain)==n){
            int u=chain[0], v=chain[1];
            ans.pb({u,v});
            for (int i=2;i<n-1;++i){
                ans.pb({u,chain[i]});
            }
            ans.pb({chain[1],chain[n-1]});
            ans.pb({chain[n-1],chain[0]});
            ans.pb({chain[0],chain[1]});
        }
        else{
            chains.pb({hii});
            merge(chains[sz(chains)-2],chains[sz(chains)-1]);
        }
    }
    cout<<sz(ans)<<"\n";
    for (auto [u,v]:ans) {cout<<u<<" "<<v<<"\n"; swap(a[u],a[v]); a[u]*=-1, a[v]*=-1;}
    // rep1(i,n) cerr<<a[i]<<" ";
    return 0;
}

//AACAB
//ABACA