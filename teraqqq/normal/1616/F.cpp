#include <bits/stdc++.h>

using namespace std;

optional<vector<int>> solve(const int n, const int m,
                            const vector<array<int, 3>>& edges) {
    // TODO(teraqqq);

    vector g(n, vector<int>(n, -1));
    vector<int> color(m), ptr(m, -1);
    for (int i = 0; i < m; ++i) {
        g[edges[i][0]][edges[i][1]] = i;
        g[edges[i][1]][edges[i][0]] = i;
        color[i] = edges[i][2];
    }

    vector<vector<int>> s;

    for (int a = 0; a < n; ++a)
    for (int b = 0; b < a; ++b)
    for (int c = 0; c < b; ++c) {
        if (g[a][b] != -1 && g[b][c] != -1 && g[a][c] != -1) {
            s.emplace_back(vector<int>(m+1));

            int val = 0;
            for (int e : array { g[a][b], g[b][c], g[a][c] }) {
                if (color[e] == -1) {
                    s.back()[e] = 1;
                } else {
                    val -= color[e];
                    if (val < 0) val += 3;
                }
            }

            s.back().back() = val;
        }
    }

    const int w = size(s);
    for (int i = 0; i < w; ++i) {
        int j0 = -1;
        for (int j = 0; j < m; ++j) {
            if (s[i][j]) j0 = j;
        }

        if (j0 < 0) {
            if (s[i].back()) return nullopt;
        } else {
            ptr[j0] = i;
            for (int t = 0; t < w; ++t) {
                if (t == i || !s[t][j0]) continue;

                if (s[t][j0] == s[i][j0]) {
                    for (int j = 0; j <= m; ++j) {
                        s[t][j] -= s[i][j];
                        if (s[t][j] < 0) s[t][j] += 3;
                    }
                } else {
                    for (int j = 0; j <= m; ++j) {
                        s[t][j] += s[i][j];
                        if (s[t][j] > 2) s[t][j] -= 3;
                    }
                }
            }
        }
    }

    cerr << "w = " << w << endl;

    for (int i = 0; i < m; ++i) {
        if (color[i] >= 0) continue;

        if (ptr[i] < 0) {
            color[i] = 0;
        } else {
            const int b = s[ptr[i]].back();
            if (s[ptr[i]][i] == 1) {
                color[i] = b;
            } else {
                color[i] = -b;
                if (color[i] < 0) color[i] += 3;
            }
        }
    }

    for (auto& x : color) {
        if (x == 0) x = 3;
    }

    return color;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<array<int, 3>> edges(m);
        for (auto& [a, b, c] : edges) {
            cin >> a >> b >> c; --a; --b;
        }

        auto d = solve(n, m, edges);

        if (d.has_value()) {
            for (int x : d.value()) {
                cout << x << ' ';
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }

        cerr << "-----------------" << endl;
    }
}