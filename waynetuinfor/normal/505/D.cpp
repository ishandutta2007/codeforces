#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn], R[maxn], topo;
int scc[maxn], sccsz[maxn];
bool v[maxn];
int nscc;

void rdfs(int now) {
    v[now] = true;
    scc[now] = nscc;
    ++sccsz[scc[now]];
    for (int u : R[now]) {
        if (!v[u]) rdfs(u);
    }
}

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) {
        if (!v[u]) dfs(u);
    }
    topo.push_back(now);
}

int go(int now) {
    v[now] = true; 
    int ret = (sccsz[scc[now]] == 1);
    for (int u : R[now]) {
        if (!v[u]) ret &= go(u);
    }
    for (int u : G[now]) {
        if (!v[u]) ret &= go(u);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); R[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) dfs(i);
    memset(v, false, sizeof(v));
    reverse(topo.begin(), topo.end());
    for (int i : topo) if (!v[i]) {
        ++nscc;
        rdfs(i); 
    }
    memset(v, false, sizeof(v));
    int ans = n;
    for (int i = 1; i <= n; ++i) if (!v[i]) ans -= go(i);
    cout << ans << endl;
    return 0;
}