#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<int> G[maxn];
vector<pair<int, int>> g[maxn];
int a[maxn], b[maxn], c[maxn], d[maxn];
int tin[maxn], low[maxn], t, bid[maxn], bcc;
stack<int> v;

void tarjan(int now, int fa) {
    tin[now] = low[now] = ++t;
    v.push(now);
    for (int u : G[now]) if (u != fa) {
        if (tin[u]) {
            low[now] = min(low[now], tin[u]);
            continue;
        }
        tarjan(u, now);
        low[now] = min(low[now], low[u]);
        if (low[u] > tin[now]) {
            ++bcc;
            while (v.size()) {
                int k = v.top(); v.pop();
                bid[k] = bcc;
                if (k == u) break;
            }
        }
    }
}

void dfs(int now, int fa, int to, int cnt) {
    if (now == to) {
        if (cnt) cout << "YES" << endl;
        else cout << "NO" << endl;
        exit(0);
        return;
    }
    for (auto u : g[now]) if (u.first != fa) dfs(u.first, now, to, cnt + d[u.first] + u.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    tarjan(1, 0);
    if (v.size()) {
        ++bcc;
        while (v.size()) bid[v.top()] = bcc, v.pop();
    }
    for (int i = 0; i < m; ++i) {
        if (bid[a[i]] == bid[b[i]]) d[bid[a[i]]] += c[i];
        else g[bid[a[i]]].emplace_back(bid[b[i]], c[i]), g[bid[b[i]]].emplace_back(bid[a[i]], c[i]);
    }
    int s, t; cin >> s >> t;
    if (bid[s] == bid[t]) {
        if (d[bid[s]]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    dfs(bid[s], 0, bid[t], d[bid[s]]);
    return 0;
}