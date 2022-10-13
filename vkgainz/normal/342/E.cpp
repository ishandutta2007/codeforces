#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 1e5+5;
vector<int> adj[MX];
int sz[MX];
bool vis[MX];
int parent[MX];
int tab[MX][20];
int depth[MX];
int ans[MX];
int find_centroid(int curr, int par, int look) {
    for(int next : adj[curr]) {
        if(next != par) {
            if(!vis[next] && sz[next]>look/2) {
                return find_centroid(next, curr, look);
            }
        }
    }
    return curr;
}
int find_size(int curr, int par=-1) {
    if(vis[curr])
        return 0;
    sz[curr] = 1;
    for(int next : adj[curr]) {
        if(next!=par) {
            sz[curr]+=find_size(next, curr);
        }
    }
    return sz[curr];
}
void init_centroid(int curr=0, int par=-1) {
    find_size(curr);
    int cen = find_centroid(curr, -1, sz[curr]);
    vis[cen] = true;
    parent[cen] = par;
    for(int next : adj[cen]) {
        if(!vis[next]) {
            init_centroid(next, cen);
        }
    }
}
void dfs(int curr=0, int par=-1) {
    for(int next : adj[curr]) {
        if(next!=par) {
            tab[next][0] = curr;
            depth[next] = depth[curr]+1;
            dfs(next, curr);
        }
    }
}
void init(int n) {
    for(int j=1;j<20;j++) {
        for(int i=0;i<n;i++) {
            tab[i][j] = tab[ tab[i][j-1] ][j-1];
        }
    }
}
int lca(int u, int v) {
    if(depth[u]<depth[v])
        swap(u, v);
    for(int bit=19;bit>=0;bit--) {
        if(depth[u]-(1<<bit)>=depth[v])
            u = tab[u][bit];
    }
    if(u==v)
        return v;
    for(int bit=19;bit>=0;bit--) {
        if(tab[u][bit]!=tab[v][bit])
            u = tab[u][bit], v = tab[v][bit];
    }
    return tab[u][0];
}
int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u]-depth[l]+depth[v]-depth[l];
}
void upd(int x) {
    ans[x] = 0;
    int curr = x;
    while(parent[curr]!=-1) {
        curr = parent[curr];
        ans[curr] = min(ans[curr], ans[x]+dist(curr, x));
    }
}
int query(int x) {
    int ret = ans[x];
    int curr = x;
    while(parent[curr]!=-1) {
        curr = parent[curr];
        ret = min(ret, dist(curr, x)+ans[curr]);
    }
    return ret;
}
int main() {
    int n, m; cin >> n >> m;
    for(int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    init(n);
    memset(parent, -1, sizeof(parent));
    init_centroid();
    for(int i=0;i<MX;i++)
        ans[i] = 200001;
    upd(0);
    for(int i=0;i<m;i++) {
        int t, v; cin >> t >> v;
        --v;
        if(t==1) {
            upd(v);
        }
        else {
            cout << query(v) << "\n";
        }
    }
}