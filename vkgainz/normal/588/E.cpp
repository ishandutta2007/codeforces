#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 1e5+5;
vector<int> adj[MX];
vector<int> c[MX];
vector<int> tab[MX][20];
int parent[MX][20];
int depth[MX];
void dfs(int curr, int par) {
    tab[curr][0] = c[curr];
    for(int next : adj[curr]) if(next!=par) {
        depth[next] = depth[curr]+1;
        parent[next][0] = curr;
        dfs(next,curr);
    }
}
vector<int> merge(vector<int> &x, vector<int> &y) {
    vector<int> ret;
    int i = 0, j = 0;
    if(x.size()==0) return y;
    if(y.size()==0) return x;
    while(ret.size()<10) {
        if(i==x.size() && j==y.size()) return ret;
        if(i==x.size()) {
            ret.push_back(y[j]);
            ++j;
            continue;
        }
        if(j==y.size()) {
            ret.push_back(x[i]);
            ++i;
            continue;
        }
        if(x[i]<y[j]) {
            ret.push_back(x[i]);
            ++i;
        }
        else {
            ret.push_back(y[j]);
            ++j;
        }
    }
    return ret;
}
int lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v);
    for(int bit=19;bit>=0;bit--) {
        if((depth[u]-(1<<bit))>=depth[v]) {
            u = parent[u][bit];
        }
    }
    if(u==v) return u;
    for(int bit=19;bit>=0;bit--) {
        if(parent[u][bit]!=parent[v][bit]) {
            u = parent[u][bit], v = parent[v][bit];
        }
    }
    return parent[v][0];
}
vector<int> get(int u, int l) {
    vector<int> curr;
    for(int bit=19;bit>=0;bit--) {
        if(depth[u]-(1<<bit)>=depth[l]) {
            curr = merge(curr, tab[u][bit]);
            u = parent[u][bit];
        }
    }
    return curr;
}
void query(int u, int v, int k) {
    int l = lca(u,v);
    vector<int> a = get(u,l), b = get(v,l);
    vector<int> ret = merge(a,b);
    ret = merge(ret, c[l]);
    int cmp = ret.size();
    k = min(k,cmp);
    cout << k << " ";
    for(int i=0;i<k;i++) cout << ret[i]+1 << " "; cout << "\n";
}
int main() {
    int n,m,q; cin >> n >> m >> q;
    for(int i=0;i<n-1;i++) {
        int u,v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<m;i++) {
        int ci; cin >> ci;
        --ci;
        if(c[ci].size()<10) c[ci].push_back(i);
    }
    dfs(0,-1);
    for(int j=1;j<20;j++) {
        for(int i=0;i<n;i++) {
            tab[i][j] = merge(tab[i][j-1], tab[ parent[i][j-1] ][j-1]);
            parent[i][j] = parent[ parent[i][j-1] ][j-1];
        }
    }
    while(q--) {
        int u,v,a; cin >> u >> v >> a;
        --u, --v;
        query(u,v,a);
    }

}