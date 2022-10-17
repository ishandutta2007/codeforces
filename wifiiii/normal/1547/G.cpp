#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 4e5 + 5;
vector<int> g[maxn], rg[maxn];
int self_loop[maxn], vis[maxn], inf_vis[maxn], uni[maxn], vis2[maxn];
void dfs(int u) {
    vis2[u] = 1;
    for(int v : g[u]) {
        if(vis2[v]) continue;
        for(int r : rg[v]) {
            if(r == u || !vis[r]) continue;
            uni[v] = 0;
        }
        if(!uni[u]) uni[v] = 0;
        dfs(v);
    }
}
int low[maxn],dfn[maxn],dfscnt=0;
int st[maxn],ins[maxn],tp=0;
int scc[maxn],sz[maxn],sccno=0;
void tarjan(int u) {
    low[u]=dfn[u]=++dfscnt;
    st[++tp]=u,ins[u]=1;
    for(int v:g[u]) {
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        ++sccno;
        int p=-1;
        while(p!=u) p=st[tp--],ins[p]=0,scc[p]=sccno,sz[sccno]++;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        sccno = tp = dfscnt = 0;
        for(int i = 1; i <= n; ++i) {
            low[i] = dfn[i] = scc[i] = sz[i] = 0;
            g[i].clear();
            rg[i].clear();
            self_loop[i] = vis[i] = inf_vis[i] = vis2[i] = 0;
            uni[i] = 1;
        }
        for(int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            rg[v].push_back(u);
            if(u == v) self_loop[u] = 1;
        }
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(vis[v]) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(!dfn[i]) tarjan(i);
        }
        for(int i = 1; i <= n; ++i) {
            if(vis[i] && (self_loop[i] || sz[scc[i]] > 1)) {
                q.push(i);
                inf_vis[i] = 1;
            }
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(inf_vis[v]) continue;
                q.push(v);
                inf_vis[v] = 1;
            }
        }
        for(int u : rg[1]) {
            if(vis[u]) uni[1] = 0;
        }
        dfs(1);
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) cout << 0 << " ";
            else if(inf_vis[i]) cout << -1 << " ";
            else if(uni[i]) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << '\n';
    }
}