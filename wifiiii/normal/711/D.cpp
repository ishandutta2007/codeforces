
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 200005;
vector<int> g[maxn];
int vis[maxn],fa[maxn];
int lp[maxn],tp=0,cnt=0;
void dfs(int u) {
    vis[u]=++cnt;
    for(int v:g[u]) {
        if(v==fa[u]) continue;
        if(vis[v]) {
            if(vis[v] < vis[u]) continue;
            for(int x=v;x!=u;x=fa[x]) lp[++tp]=x;
            lp[++tp]=u;
            continue;
        }
        fa[v]=u;
        dfs(v);
    }
}
const int mod=1e9+7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    ll ans=1;
    for(int i=1;i<=n;++i) {
        if(!vis[i]) {
            cnt=tp=0;
            dfs(i);
            ans=ans*(fpow(2,cnt)-fpow(2,cnt-tp+1))%mod;
        }
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}