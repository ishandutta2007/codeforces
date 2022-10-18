#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    for (int b = 20; b > 0; b--) {
        int mask = (1 << b) - 1;
        vector<pair<int, int>> edges(n);
        vector<vector<int>> g(mask + 1);
        for (int i = 0; i < n; i++) {
            int x = a[2 * i] & mask;
            int y = a[2 * i + 1] & mask;
            edges[i] = {x, y};
            g[x].emplace_back(i);
            g[y].emplace_back(i);
        }
        bool ok = true;
        for (int i = 0; i <= mask; i++) {
            if (g[i].size() & 1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        vector<bool> used(n);
        int sz = 0;
        int st;
        vector<int> order(n);
        function<void(int)> dfs = [&](int v) {
            while (!g[v].empty()) {
                int id = g[v].back();
                g[v].pop_back();
                if (used[id]) {
                    continue;
                }
                used[id] = true;
                dfs(v ^ edges[id].first ^ edges[id].second);
                order[sz++] = id;
            }
        };
        for (int i = 0; i <= mask; i++) {
            if (g[i].empty()) {
                continue;
            }
            st = i;
            dfs(i);
            if (sz != n) {
                ok = false;
            }
            break;
        }
        if (!ok) {
            continue;
        }
        cout << b << '\n';
        for (int i = 0; i < n; i++) {
            int id = order[i];
            if (edges[id].first == st) {
                cout << 2 * id + 1 << " " << 2 * id + 2 << " ";
                st = edges[id].second;
            } else {
                cout << 2 * id + 2 << " " << 2 * id + 1 << " ";
                st = edges[id].first;
            }
        }
        cout << '\n';
        return 0;
    }
    cout << 0 << '\n';
    for (int i = 0; i < 2 * n; i++) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}