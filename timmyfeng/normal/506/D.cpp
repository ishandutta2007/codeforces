#include <bits/stdc++.h>
using namespace std;

#include<bits/extc++.h>
using namespace __gnu_pbds;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using hash_map = gp_hash_table<int, int, splitmix64_hash>;

const int N = 100000;
const int B = 256;

vector<array<int, 2>> edges[N];
array<int, 2> queries[N];
hash_map ans[N];
bool first[N];

vector<int> adj[N];
int component[N];

void dfs(int u, int x) {
    component[u] = x;
    for (auto c : adj[u]) {
        if (component[c] == 0) {
            dfs(c, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[--c].push_back({--a, --b});
    }

    int q;
    cin >> q;

    set<array<int, 2>> met;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;

        if (--u > --v) {
            swap(u, v);
        }

        queries[i] = {u, v};
        if (met.count(queries[i]) == 0) {
            first[i] = true;
            met.insert(queries[i]);
            ans[u][v] = 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        vector<int> nodes;
        for (auto [u, v] : edges[i]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            nodes.push_back(u);
            nodes.push_back(v);
        }

        sort(nodes.begin(), nodes.end());
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        int k = 0;
        for (auto u : nodes) {
            if (component[u] == 0) {
                dfs(u, ++k);
            }
        }

        int s = nodes.size();
        if (s < B) {
            for (int a = 0; a < s; ++a) {
                for (int b = a + 1; b < s; ++b) {
                    int u = nodes[a], v = nodes[b];
                    if (component[u] == component[v] && ans[u].find(v) != ans[u].end()) {
                        ++ans[u][v];
                    }
                }
            }
        } else {
            for (int j = 0; j < q; ++j) {
                auto [u, v] = queries[j];
                if (first[j] && component[u] > 0 && component[u] == component[v]) {
                    ++ans[u][v];
                }
            }
        }

        for (auto u : nodes) {
            component[u] = 0;
            adj[u].clear();
        }
    }

    for (int i = 0; i < q; ++i) {
        auto [u, v] = queries[i];
        cout << ans[u][v] << "\n";
    }
}