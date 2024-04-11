#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
vector<pair<int, int>> adj[MX];
int par[MX], sz[MX], depth[MX];
int tab[MX][21], parent[MX][21];
int find_set(int x) {
    if(x==par[x]) return x;
    return par[x] = find_set(par[x]);
}
bool cmp(tuple<int, int, int, int> &a, tuple<int, int, int, int> &b) {
    return get<2>(a)<get<2>(b);
}
void dfs(int curr, int par) {
    for(auto &next : adj[curr]) if(next.f!=par) {
        tab[next.f][0] = next.s;
        parent[next.f][0] = curr;
        depth[next.f] = depth[curr]+1;
        dfs(next.f,curr);
    }
}
int lca(int u, int v, int w) {
    if(depth[u]<depth[v]) swap(u,v);
    for(int bit=20;bit>=0;bit--) {
        if(depth[u]-(1<<bit)>=depth[v]) u = parent[u][bit];
    }
    if(u==v) return u;
    for(int bit=20;bit>=0;bit--) {
        if(parent[u][bit]!=parent[v][bit]) {
            u = parent[u][bit], v = parent[v][bit];
        }
    }
    return parent[v][0];
}
int mx(int u, int l) {
    int ret = 0;
    for(int bit=20;bit>=0;bit--) {
        if(depth[u]-(1<<bit)>=depth[l]) {
            ret = max(ret, tab[u][bit]);
            u = parent[u][bit];
        }
    }
    return ret;
}
int query(int u, int v,int w) {
    int l = lca(u,v,w);
    int rem = max(mx(u,l), mx(v,l));
    return w-rem;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<tuple<int, int, int, int>> edge(m);
    for(int i=0;i<m;i++) {
        int u,v,w; cin >> u >> v >> w;
        --u, --v;
        edge[i] = {u,v,w,i};
    }
    sort(edge.begin(),edge.end(),cmp);
    ll mstSz = 0LL;
    for(int i=0;i<n;i++) par[i] = i, sz[i] = 1;
    for(auto &it : edge) {
        int u = get<0>(it);
        int v = get<1>(it);
        int w = get<2>(it);
        int x = find_set(u), y = find_set(v);
        if(x==y) continue;
        if(sz[x]>sz[y]) swap(x,y);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        sz[y]+=sz[x];
        par[x] = y;
        mstSz+=w;
    }
    dfs(0,-1);
    for(int j=1;j<20;j++) {
        for(int i=0;i<n;i++) {
            tab[i][j] = max(tab[i][j-1], tab[ parent[i][j-1] ][j-1]);
            parent[i][j] = parent[ parent[i][j-1] ][j-1];
        }
    }
    ll ans[m];
    for(int i=0;i<m;i++) {
        int u = get<0>(edge[i]);
        int v = get<1>(edge[i]);
        int w = get<2>(edge[i]);
        ans[get<3>(edge[i])] = mstSz+query(u,v,w);
    }
    for(int i=0;i<m;i++) cout << ans[i] << "\n";
}