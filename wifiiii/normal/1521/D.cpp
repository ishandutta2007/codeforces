#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
vector<int> g[maxn];
int dp[maxn][2];
vector<int> nxt[maxn][2];
void dfs(int u, int fa) {
    int id1 = -1, id2 = -1, md1 = 1e9, md2 = 1e9, sum = 0;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        assert(dp[v][1] <= dp[v][0]);
        int d = dp[v][0] - dp[v][1];
        if(d < md1) {
            id2 = id1;
            md2 = md1;
            md1 = d;
            id1 = v;
        } else if(d < md2) {
            md2 = d;
            id2 = v;
        }
        sum += dp[v][1];
    }
    dp[u][0] = g[u].size() - (fa != 0) + sum; // cut all
    nxt[u][0].clear();
    if(id1 != -1 && md1 == 0) { // reserve id1
        dp[u][0] = g[u].size() - (fa != 0) + sum - 1;
        nxt[u][0].push_back(id1);
    }
    dp[u][1] = dp[u][0];
    nxt[u][1] = nxt[u][0];
    if(id1 != -1 && id2 != -1 && md1 == 0 && md2 == 0) { // reserve id1 and id2
        dp[u][1] = g[u].size() - (fa != 0) - 2 + sum;
        nxt[u][1] = vector<int>{id1, id2};
    }
}
vector<pair<int,int>> qwq, qaq;
vector<int> G[maxn];
void dfs2(int u, int fa, int op) {
    for(int v : g[u]) {
        if(v == fa) continue;
        int cut = 1;
        for(int p : nxt[u][op]) if(p == v) cut = 0;
        dfs2(v, u, cut);
        if(!cut) {
            G[u].push_back(v);
            G[v].push_back(u);
        } else {
            qaq.push_back({u, v});
        }
    }
}
int vis[maxn];
vector<int> bamboo;
void dfs3(int u) {
    if(G[u].size() == 1 || G[u].size() == 0) bamboo.push_back(u);
    vis[u] = 1;
    for(int v : G[u]) {
        if(vis[v]) continue;
        dfs3(v);
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) g[i].clear(), G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        qwq.clear();
        qaq.clear();
        dfs2(1, 0, 1);
        for(int i = 1; i <= n; ++i) vis[i] = 0;
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            bamboo.clear();
            dfs3(i);
            qwq.push_back({bamboo[0], bamboo.back()});
        }
        cout << qaq.size() << endl;
        for(int i = 0; i < qaq.size(); ++i) {
            cout << qaq[i].first << " " << qaq[i].second << " " << qwq[i].second << " " << qwq[i+1].first << '\n';
        }
    }
}