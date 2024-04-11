#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

int degree[N], discard[N];
vector<int> adj[N];

struct compare {

    bool operator()(array<int, 3> a, array<int, 3> b) const {
        long long c = (long long) a[0] * b[1] - (long long) b[0] * a[1];
        if (c == 0) {
            return a[2] < b[2];
        } else {
            return c < 0;
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= k; ++i) {
        int u;
        cin >> u;
        discard[u] = -1;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<array<int, 3>, compare> cities;
    for (int i = 1; i <= n; ++i) {
        if (discard[i] != -1) {
            for (auto j : adj[i]) {
                degree[i] += discard[j] != -1;
            }
            cities.insert({degree[i], (int) adj[i].size(), i});
        }
    }

    array<int, 3> ans = *cities.begin();
    ans[2] = 0;

    for (int i = 1; !cities.empty(); ++i) {
        auto [x, y, u] = *cities.begin();
        cities.erase(cities.begin());
        discard[u] = i;

        for (auto v : adj[u]) {
            if (discard[v] == 0) {
                cities.erase({degree[v], (int) adj[v].size(), v});
                cities.insert({--degree[v], (int) adj[v].size(), v});
            }
        }

        if (!cities.empty()) {
            array<int, 3> cur = *cities.begin();
            cur[2] = i;

            if (compare()(ans, cur)) {
                ans = cur;
            }
        }
    }

    vector<int> s;
    for (int i = 1; i <= n; ++i) {
        if (discard[i] > ans[2]) {
            s.push_back(i);
        }
    }

    cout << s.size() << "\n";
    for (auto i : s) {
        cout << i << " ";
    }
    cout << "\n";
}