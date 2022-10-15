// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
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
const int INF=LLONG_MAX/2;
const double EPS=1e-9;
const int N=500007;
const int K=20;
mt19937 rng(1234);

int n;
vector<pii> g[N];
int x[N],y[N];
vector<pii> pd[N];
vi p;
bool vis[N];

void decomp(){
    for (int i=2;i<=200000;++i){
        if (vis[i]) continue;
        p.pb(i);
        for (int j=1;i*j<=200000;++j) vis[i*j]=1;
    }
    for (int i=2;i<=200000;++i){
        int tmp=i;
        for (int j=0;p[j]*p[j]<=tmp;++j){
            if (tmp%p[j]==0){
                int t=0;
                while (tmp%p[j]==0){
                    tmp/=p[j], t++; 
                }
                pd[i].pb({p[j],t});
            }
        }
        if (tmp>1) pd[i].pb({tmp,1});
    }
}
int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}

int now[N];
int mn[N];
int res[N];
vi get_pm;
void dfs1(int u,int p){
    // cerr<<"cur: "<<u<<endl;
    // rep(i,10) cerr<<now[i]<<" ";
    // cerr<<endl;
    for (auto [v,idx]:g[u]){
        if (v==p) continue;
        bool fk=0;
        if (idx<0) fk=1, idx=~idx;
        for (auto [a,b]:pd[x[idx]]) now[a]+=b*(fk?1:-1), mn[a]=min(mn[a],now[a]);
        for (auto [a,b]:pd[y[idx]]) now[a]+=b*(fk?-1:1), mn[a]=min(mn[a],now[a]);
        dfs1(v,u);
        for (auto [a,b]:pd[x[idx]]) now[a]+=b*(fk?-1:1), mn[a]=min(mn[a],now[a]);
        for (auto [a,b]:pd[y[idx]]) now[a]+=b*(fk?1:-1), mn[a]=min(mn[a],now[a]);
    }
}

void dfs2(int u,int p,int val){
    res[u]=val;
    for (auto [v,idx]:g[u]){
        if (v==p) continue;
        bool fk=0;
        if (idx<0) fk=1, idx=~idx;
        int tval=val;
        if (fk) tval=val*x[idx]%mod*modpow(y[idx],mod-2)%mod;
        else tval=val*y[idx]%mod*modpow(x[idx],mod-2)%mod;
        dfs2(v,u,tval);
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    decomp();
    while (_--){
        cin>>n;
        get_pm.clear();
        rep(i,n) g[i].clear();
        rep(i,n-1){
            int u,v;
            cin>>u>>v>>x[i]>>y[i];
            int gg=__gcd(x[i],y[i]);
            x[i]/=gg, y[i]/=gg;
            for (auto [a,b]:pd[x[i]]) get_pm.pb(a);
            for (auto [a,b]:pd[y[i]]) get_pm.pb(a);
            u--, v--;
            g[u].pb({v,i}), g[v].pb({u,~i});
        } 
        sort(range(get_pm));
        get_pm.erase(unique(range(get_pm)),get_pm.end());
        for (auto c:get_pm) now[c]=mn[c]=0;
        // res[0]=1;
        dfs1(0,-1);
        dfs2(0,-1,1);
        int ans=0;
        for (int i=0;i<n;++i) ans=(ans+res[i])%mod;
        for (auto c:get_pm){
            // cerr<<c<<" "<<mn[c]<<endl;
            ans=ans*modpow(c,-mn[c])%mod;
        } 
        cout<<ans<<"\n";
    }
    return 0;
}


/*

*/