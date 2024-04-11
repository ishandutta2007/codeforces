#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn << 1], R[maxn << 1], topo, scc[maxn << 1];
bool v[maxn << 1];
int p[maxn], cnt, id[maxn << 1], g[maxn], ans[maxn << 1];

void rdfs(int now) {
    v[now] = true;
    for (int u : R[now]) if (!v[u]) rdfs(u);
    topo.push_back(now);
}

void dfs(int now) {
    id[now] = cnt;
    v[now] = true;
    for (int u : G[now]) if (!v[u]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<int> s;
    for (int i = 1; i <= n; ++i) s.push_back(i);
    sort(s.begin(), s.end(), [&](const int& i, const int& j) { return p[i] < p[j]; });
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        int c = lower_bound(s.begin(), s.end(), a - p[i], [&](const int& i, const int& j) { return p[i] < j; }) - s.begin();
        int d = lower_bound(s.begin(), s.end(), b - p[i], [&](const int& i, const int& j) { return p[i] < j; }) - s.begin();
        bool cc = (c < n && p[s[c]] == a - p[i]), dd = (d < n && p[s[d]] == b - p[i]);
        if (!cc && !dd) ok = false;
        else if (!cc) {
            G[i << 1].push_back(i << 1 | 1); R[i << 1 | 1].push_back(i << 1);
            G[s[d] << 1].push_back(s[d] << 1 | 1); R[s[d] << 1 | 1].push_back(s[d] << 1);
        } 
        else if (!dd) {
            G[i << 1 | 1].push_back(i << 1); R[i << 1].push_back(i << 1 | 1);
            G[s[c] << 1 | 1].push_back(s[c] << 1); R[s[c] << 1].push_back(s[c] << 1 | 1);
        }
        else {
            G[i << 1].push_back(s[c] << 1), R[s[c] << 1].push_back(i << 1);
            G[i << 1 | 1].push_back(s[c] << 1 | 1), R[s[c] << 1 | 1].push_back(i << 1 | 1);
            G[i << 1 | 1].push_back(s[d] << 1 | 1), R[s[d] << 1 | 1].push_back(i << 1 | 1);
            G[i << 1].push_back(s[d] << 1), R[s[d] << 1].push_back(i << 1);
        }
        if (!ok) return cout << "NO" << endl, 0;
    }
    for (int i = 2; i <= n * 2 + 1; ++i) if (!v[i]) rdfs(i);
    reverse(topo.begin(), topo.end());
    memset(v, false, sizeof(v));
    for (int i : topo) if (!v[i]) {
        ++cnt;
        dfs(i);
    }
    for (int i = 2; i <= n * 2 + 1; ++i) {
        scc[id[i]].push_back(i);
        if (id[i ^ 1] == id[i]) return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        if (id[i << 1] > id[i << 1 | 1]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    cout << endl;
    return 0;
}