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
typedef pair<int,int> pii;

const int maxn = 100005;
vector<int> g[maxn];
int f[maxn][20], dep[maxn];
void dfs(int u,int fa)
{
    for(int v : g[u])
    {
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        for(int i=1;i<=19;++i) f[v][i]=f[f[v][i-1]][i-1];
        dfs(v, u);
    }
}
void dfs2(int u,int fa) {
    for(int v : g[u]) {
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs2(v, u);
    }
}
int lca(int u,int v)
{
    if(dep[u] < dep[v]) swap(u, v);
    for(int d=dep[u]-dep[v],i=19;i>=0;--i) if(d&(1<<i)) u=f[u][i];
    if(u == v) return u;
    for(int i=19;i>=0;--i) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int dis(int u,int v) {return dep[u]+dep[v]-2*dep[lca(u,v)];}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        ii g[i].clear();
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dep[1] = 0;
        dfs2(1, 0);
        int rt = 0;
        for(int i=1;i<=n;++i) if(dep[i] > dep[rt]) rt = i;
        dep[rt] = 0;
        int d = 0;
        for(int i=0;i<=19;++i) f[rt][i]=0;
        dfs(rt, 0);
        for(int i=1;i<=n;++i) d = max(d, dep[i]);
        if(2*da>=db || dis(a,b)<=da || d<=2*da) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}