#include <bits/stdc++.h>
using namespace std;
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
    vector<pair<int, int>> edges(n);
    vector<vector<int>> g(2 * n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(i);
        g[y].emplace_back(i);
        edges[i] = make_pair(x, y);
    }
    vector<vector<int>> a;
    vector<int> cv(2 * n);
    vector<int> ce(n);
    for (int i = 0; i < 2 * n; i++) {
        if (cv[i]) {
            continue;
        }
        vector<int> b;
        function<void(int)> Dfs = [&](int v) {
            cv[v] = 1;
            for (int id : g[v]) {
                if (ce[id]) {
                    continue;
                }
                ce[id] = 1;
                int to = v ^ edges[id].first ^ edges[id].second;
                if (cv[to]) {
                    b.emplace_back(to);
                    b.emplace_back(v);
                    continue;
                }
                b.emplace_back(to);
                Dfs(to);
                b.emplace_back(v);
            }
        };
        Dfs(i);
        if (b.size() == 2) {
            cout << -1 << '\n';
            return 0;
        }
        debug(b);
        if (!b.empty()) {
            a.emplace_back(b);
        }
    }
    vector<vector<string>> t(2, vector<string>(2));
    vector<vector<int>> c(2);
    cout << 2 << " " << n << '\n';
    cout << '\n';
    for (auto b : a) {
        int sz = (int) b.size();
        assert(sz % 2 == 0);
        reverse(b.begin() + sz / 2, b.end());
        c[0].insert(c[0].end(), b.begin(), b.begin() + sz / 2);
        c[1].insert(c[1].end(), b.begin() + sz / 2, b.end());
        if (sz % 4 == 0) {
            string s;
            for (int i = 0; i < sz / 4 - 1; i++) {
                s += "LR";
            }
            t[0][0] += s + "LR";
            t[0][1] += s + "LR";
            t[1][0] += "U" + s + "U";
            t[1][1] += "D" + s + "D";
        } else {
            string s;
            for (int i = 0; i < sz / 4; i++) {
                s += "LR";
            }
            t[0][0] += s + "U";
            t[0][1] += s + "D";
            t[1][0] += "U" + s;
            t[1][1] += "D" + s;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] + 1 << " \n"[j == n - 1];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << t[i][j] << '\n';
        }
        cout << '\n';
    }
    return 0;
}