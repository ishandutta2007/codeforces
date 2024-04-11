#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

const int maxn=4007;
int t,n,m,a[maxn],b[maxn],sz[maxn];
pair<int,long long> f[maxn][maxn],g[maxn];
vector<int> vec[maxn];

void dfs(int u,int p){
    sz[u]=1;
    for (int i=1;i<=m;++i){
        f[u][i]={0,-1e15};
    }
    f[u][0]={0,b[u]-a[u]};
    for (auto c:vec[u]){
        if (c==p) continue;
        dfs(c,u);
        for (int i=0;i<=sz[u]+sz[c];++i){
            g[i]={-1,0};
        }
        for (int i=0;i<sz[u];++i){
            for (int j=0;j<sz[c];++j){
                setmax(g[i+j],{f[u][i].F+f[c][j].F,f[u][i].S+f[c][j].S});
                setmax(g[i+j+1],{f[u][i].F+f[c][j].F+(f[c][j].S>0),f[u][i].S});
            }
        }
        sz[u]+=sz[c];
        for (int i=0;i<sz[u];++i){
            f[u][i]=g[i];
        }  
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>m;
        rep1(i,n) cin>>a[i];
        rep1(i,n) cin>>b[i];
        rep1(i,n) vec[i].clear();
        rep1(i,n-1) {int u,v; cin>>u>>v; vec[u].push_back(v), vec[v].push_back(u);}
        dfs(1,0);
        cout<<f[1][m-1].F+(f[1][m-1].S>0)<<endl;
    }
    return 0;
}