#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
vector<int> g[maxn], r[maxn], tp;
vector<int> z[maxn];
int sz, scc[maxn];
bool v[maxn];

void dfs(int x) {
    v[x] = true;
    for (int u : g[x]) if (!v[u]) dfs(u);
    tp.push_back(x);
}

void rdfs(int x) {
    scc[x] = sz;
    for (int u : r[x]) if (!scc[u]) rdfs(u);
}

bool reach(int x, int t) {
    if (x == t) return true;
    bool f = false;
    v[x] = true;
    for (int u : z[x]) if (!v[u]) f |= reach(u, t);
    return f;
} 

int main() {
    int n, m, s; cin >> n >> m >> s; --s;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back(b);
        r[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) if (!v[i]) dfs(i);
    reverse(tp.begin(), tp.end());
    for (int i : tp) if (!scc[i]) ++sz, rdfs(i);
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) if (scc[i] != scc[j]) z[scc[i]].push_back(scc[j]);
    }    
    // reverse(tp.begin(), tp.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        memset(v, false, sizeof(v));
        if (!reach(scc[s], scc[tp[i]])) z[scc[s]].push_back(scc[tp[i]]), ++ans;
    }
    printf("%d\n", ans);
}