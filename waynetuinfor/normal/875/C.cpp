#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> s[maxn], G[maxn + maxn], R[maxn + maxn];
vector<int> tp;
bool v[maxn + maxn];
int scc[maxn + maxn], cnt;

void add_edge(int a, int b) {
    G[a].push_back(b);
    R[b].push_back(a);
}

void ban(int a) { add_edge(a, a ^ 1); }

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) {
        if (!v[u]) dfs(u);
    }
    tp.push_back(now);
}

void rdfs(int now) {
    scc[now] = cnt;
    for (int u : R[now]) {
        if (!scc[u]) rdfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l; cin >> l;
        s[i].resize(l);
        for (int j = 0; j < l; ++j) cin >> s[i][j];
    }
    for (int i = 1; i < n; ++i) {
        int pos = -1;
        for (int j = 0; j < min(s[i].size(), s[i + 1].size()); ++j) {
            if (s[i][j] != s[i + 1][j]) {  pos = j; break; }
        }
        if (pos == -1) {
            if (s[i].size() > s[i + 1].size()) return cout << "No" << endl, 0;
            continue;
        } 
        if (s[i][pos] < s[i + 1][pos]) {
            add_edge(s[i][pos] << 1, s[i + 1][pos] << 1);
            add_edge(s[i + 1][pos] << 1 | 1, s[i][pos] << 1 | 1);
        } else {
            ban(s[i][pos] << 1);
            ban(s[i + 1][pos] << 1 | 1);
        }
    }
    // cout << "done add edge" << endl;
    for (int i = 1; i <= m + m; ++i) {
        if (!v[i]) dfs(i);
    }
    // cout << "done dfs" << endl;
    reverse(tp.begin(), tp.end());
    for (int u : tp) {
        if (!scc[u]) ++cnt, rdfs(u);
    }
    for (int i = 1; i <= m; ++i) {
        if (scc[i << 1] == scc[i << 1 | 1]) return cout << "No" << endl, 0;
    }
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        if (scc[i << 1] < scc[i << 1 | 1]) ans.push_back(i);
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}