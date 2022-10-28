#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int timer[N], par[N];

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    timer[v] = min(timer[u], timer[v]);
    par[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        map<int, vector<pair<int, int>>> rows, cols;
        iota(par, par + n, 0);

        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y >> timer[i];
            rows[x].push_back({y, i});
            cols[y].push_back({x, i});
        }

        for (auto &[x, r] : rows) {
            sort(r.begin(), r.end());
            for (int i = 1; i < (int) r.size(); ++i) {
                if (r[i].first - r[i - 1].first <= k) {
                    unite(r[i].second, r[i - 1].second);
                }
            }
        }

        for (auto &[y, c] : cols) {
            sort(c.begin(), c.end());
            for (int i = 1; i < (int) c.size(); ++i) {
                if (c[i].first - c[i - 1].first <= k) {
                    unite(c[i].second, c[i - 1].second);
                }
            }
        }

        vector<int> components;
        for (int i = 0; i < n; ++i) {
            if (par[i] == i) components.push_back(timer[i]);
        }
        sort(components.rbegin(), components.rend());

        int ans = 0;
        while (ans + 1 < (int) components.size() && components[ans + 1] > ans) ++ans;

        cout << ans << "\n";
    }
}