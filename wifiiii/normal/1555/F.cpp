#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500005;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int a[maxn], b[maxn], c[maxn], ans[maxn];
struct edge {
    int v, w;
};
vector<edge> g[maxn];
int f[maxn][20], dep[maxn], dis[maxn], vis[maxn], xs[maxn];
int id[maxn], sz[maxn], root[maxn], dfscnt=0;
void dfs(int u,int fa,int p) {
    id[u] = ++dfscnt;
    sz[u] = 1;
    root[u] = p;
    for(edge e : g[u]) {
        int v = e.v;
        if(v == fa) continue;
        dis[v] = dis[u] + e.w;
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        for(int i=1;i<=19;++i) f[v][i] = f[f[v][i-1]][i-1];
        xs[v] = xs[u] ^ e.w;
        dfs(v, u, p);
        sz[u] += sz[v];
    }
}
int lca(int u,int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int d=dep[u]-dep[v],i=19;i>=0;--i) if(d&(1<<i)) u=f[u][i];
    if(u == v) return u;
    for(int i=19;i>=0;--i) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int dist(int u, int v) {
    return ((dis[u]+dis[v]-2*dis[lca(u,v)])%2+2)%2;
}

template<typename T>
struct BIT {
    vector<T> a;
    int n;
    BIT() {}
    BIT(int _n) {n=_n+1;a.resize(n+1);}
    void init(int _n) {n=_n+1;a.resize(n+1);}
    void add(int x,T v){++x;for(;x<=n;x+=x&-x)a[x]+=v;}
    void add(int l,int r,T v) {add(l,v);add(r+1,-v);}
    T sum(int x) {++x;T ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) par[i] = i;
    for(int i = 1; i <= q; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = u, b[i] = v, c[i] = w;
        if(find(u) != find(v)) {
            ans[i] = 1;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            par[find(u)] = find(v);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(id[i]) continue;
        dfs(i, 0, i);
    }
    for(int i = 1; i <= n; ++i) par[i] = i;
    BIT<int> bit(n+1);
    for(int i = 1; i <= q; ++i) {
        if(ans[i]) continue;
        int u = a[i], v = b[i], w = c[i];
        if((xs[u] ^ xs[v]) == w) continue;
        int l = lca(u, v);
        if(bit.sum(id[u]) != bit.sum(id[l]) || bit.sum(id[v]) != bit.sum(id[l])) continue;
        ans[i] = 1;
        while(u != l) {
            bit.add(id[u], id[u]+sz[u]-1, 1);
            assert(u==par[u]);
            par[u]=f[u][0];
            u=f[u][0];
        }
        while(v != l) {
            bit.add(id[v], id[v]+sz[v]-1, 1);
            assert(v==par[v]);
            par[v]=f[v][0];
            v=f[v][0];
        }
    }
    for(int i = 1; i <= q; ++i) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}