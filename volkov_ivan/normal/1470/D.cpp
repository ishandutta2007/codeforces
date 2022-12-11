#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
vector <int> g[N];
int color[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        color[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    set <int> connect;
    connect.insert(1);
    vector <int> res;
    while (!connect.empty()) {
        int v = *connect.begin();
        assert(color[v] == -1);
        res.push_back(v);
        color[v] = 1;
        connect.erase(connect.begin());
        vector <int> not_relaxed;
        for (int u : g[v]) {
            if (connect.find(u) != connect.end())
                connect.erase(u);
            assert(color[u] != 1);
            if (color[u] == -1)
                not_relaxed.push_back(u);
            color[u] = 0;
        }
        for (int u : not_relaxed) {
            for (int u2 : g[u]) {
                if (color[u2] == -1)
                    connect.insert(u2);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << res.size() << "\n";
    for (int elem : res) {
        cout << elem << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}