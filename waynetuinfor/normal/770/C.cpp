#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn], ma, ans;
bool v[maxn], go[maxn];

void dfs(int now) {
    v[now] = true;
    go[now] = true;
    for (int u : G[now]) {
        if (!v[u]) dfs(u);
        if (go[u]) {
            cout << "-1" << endl;
            exit(0);
        }
    }
    go[now] = false;
    ans.push_back(now);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int t; cin >> t; ma.push_back(t);
    }
    for (int i = 1; i <= n; ++i) {
        int t; cin >> t; while (t--) {
            int u; cin >> u;
            G[i].emplace_back(u);
        }
    }
    for (int i : ma) if (!v[i]) dfs(i);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}