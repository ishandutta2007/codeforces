#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
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
typedef pair<int, int> pii;

const int maxn = 100005;
int a[maxn], ans[maxn];
vector<int> g[maxn];
vector<pair<int,int>> q[maxn];
int sz[maxn], son[maxn];
void dfs(int u,int fa) {
    sz[u]=1;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[son[u]]<sz[v])son[u]=v;
    }
}
int bit[maxn];
void add(int x,int v) {for(;x<maxn;x+=x&-x) bit[x]+=v;}
int sum(int x) {int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
int cnt[maxn];
inline void upd(int u, int v) {
    if(cnt[a[u]]) add(cnt[a[u]], -1);
    cnt[a[u]] += v;
    if(cnt[a[u]]) add(cnt[a[u]], 1);
}
void dfs_add(int u,int fa,int c) {
    upd(u,c);
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs_add(v,u,c);
    }
}
void dfs2(int u,int fa,int keep) {
    for(int v:g[u]) {
        if(v==fa || v==son[u]) continue;
        dfs2(v,u,0);
    }
    if(son[u]) dfs2(son[u],u,1);
    upd(u,1);
    for(int v:g[u]) if(v!=fa && v!=son[u]) dfs_add(v,u,1);
    for(auto p:q[u]) {
        ans[p.second]=sum(maxn-1)-sum(p.first-1);
    }
    if(!keep) {
        upd(u,-1);
        for(int v:g[u]) if(v!=fa) dfs_add(v,u,-1);
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=m;++i) {
        int v,k;
        cin>>v>>k;
        q[v].push_back({k, i});
    }
    dfs(1,0);
    dfs2(1,0,1);
    for(int i=1;i<=m;++i) cout<<ans[i]<<"\n";
}