#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;

const int mod = 1e9+7;
vector<int> g[100005];
const int maxn = 100005;
int sz[maxn], par[maxn];
ll p[maxn],p2[maxn];
void dfs(int u,int fa) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        vl v;
        for(int i=1;i<=n;++i) {
            for(int u:g[i]) {
                if(par[i] == u) continue;
                v.pb(1ll*sz[u]*(n-sz[u]));
            }
        }
        sort(all(v));
        reverse(all(v));
        int m;
        cin >> m;
        for(int i=0;i<m;++i) cin>>p[i];
        sort(p,p+m);
        reverse(p,p+m);
        if(m > n-1) {
            p2[0]=1;
            for(int i=0;i<=m-n+1;++i) p2[0]=p2[0]*p[i]%mod;
            for(int i=1;i<n-1;++i) p2[i]=p[i+m-n+1];
        } else {
            for(int i=0;i<m;++i) p2[i]=p[i];
            for(int i=m;i<n-1;++i) p2[i]=1;
        }
        ll ans=0;
        for(int i=0;i<n-1;++i) {
            ans+=v[i]%mod*p2[i]%mod;
        }
        cout<<ans%mod<<endl;
        ii g[i].clear();
    }
}