#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> indeg(n);
    int ans = n;
    auto add_edge = [&](int u, int v) {
        if (u > v) swap(u, v);
        ans -= indeg[u] == 0;
        ++indeg[u];
    };
    auto remove_edge = [&](int u, int v) {
        if (u > v) swap(u, v);
        --indeg[u];
        ans += indeg[u] == 0;
    };
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }
    int q;
    cin >> q;
    for (int z = 0; z < q; ++z) {
        int type;
        cin >> type;
        if (type == 3) {
            cout << ans << '\n';
        }
        else {
            int u, v;
            cin >> u >> v;
            --u, --v;
            type == 1 ? add_edge(u, v) : remove_edge(u, v);
        }
    }
    exit(0);
}