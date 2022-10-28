#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<array<int, 3>> adj[N];
string ans[N];

void dfs(int u) {
    while (!adj[u].empty()) {
        auto [v, iu, iv] = adj[u].back(); adj[u].pop_back();
        if (ans[u][iu] != '?') continue;

        ans[u][iu] = 'L', ans[v][iv] = 'R';

        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;

    map<int, pair<int, int>> prv;

    for (int i = 0; i < m; ++i) {
        int n; cin >> n;

        ans[i] = string(n, '?');
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;

            if (prv.contains(a)) {
                auto [i_oth, j_oth] = prv[a];
                adj[i].push_back({i_oth, j, j_oth});
                adj[i_oth].push_back({i, j_oth, j});
                prv.erase(a);
            } else prv[a] = {i, j};
        }
    }

    if (!prv.empty()) {
        cout << "NO\n";
        exit(0);
    }

    for (int i = 0; i < m; ++i) dfs(i);

    cout << "YES\n";
    for (int i = 0; i < m; ++i) cout << ans[i] << "\n";
}