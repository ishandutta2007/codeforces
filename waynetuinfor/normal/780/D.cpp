#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
vector<int> G[maxn], R[maxn], topo;
string s[2][maxn];
bool v[maxn];
int c, scc[maxn], ans[maxn];

void add_edge(int a, int b) {
    G[a].push_back(b);
    R[b].push_back(a);
}

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) if (!v[u]) dfs(u);
    topo.push_back(now);
}

void rdfs(int now) {
    v[now] = true;
    scc[now] = c;
    for (int u : R[now]) if (!v[u]) rdfs(u);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string a, b; cin >> a >> b;
        s[0][i] = a.substr(0, 3);
        s[1][i] = a.substr(0, 2) + b[0];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if (s[0][i] == s[0][j]) add_edge(i << 1, j << 1 | 1);
            if (s[1][i] == s[0][j]) add_edge(i << 1 | 1, j << 1 | 1);
            if (s[0][i] == s[0][j]) add_edge(i << 1 | 1, j << 1 | 1);
            if (s[0][i] == s[1][j]) add_edge(i << 1, j << 1);
            if (s[1][i] == s[1][j]) add_edge(i << 1 | 1, j << 1);
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!v[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end()); memset(v, false, sizeof(v));
    for (int u : topo) {
        if (!v[u]) ++c, rdfs(u);
    }
    for (int i = 0; i < n; ++i) {
        if (scc[i << 1] == scc[i << 1 | 1]) return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        if (scc[i << 1 | 1] > scc[i << 1]) cout << s[1][i] << endl;
        else cout << s[0][i] << endl;
    } 
    return 0;
}