#include <bits/stdc++.h>
using namespace std;

struct maximum_matching {
    maximum_matching(int n) : n(n) {
        mate.assign(n, -1);
        parity.resize(n);
        blossom.resize(n);
        parent.resize(n);
        last.resize(n);
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void augment(int u) {
        while (u != -1) {
            int u_nxt = mate[parent[u]];
            mate[u] = parent[u];
            mate[parent[u]] = u;
            u = u_nxt;
        }
    }

    int lca(int u, int v) {
        ++timer;
        while (true) {
            if (u != -1) {
                if (last[u] == timer) return u;
                last[u] = timer;
                u = (mate[u] == -1) ? -1 : blossom[parent[mate[u]]];
            }
            swap(u, v);
        }
    }

    void merge(int u, int v, int p) {
        while (blossom[u] != p) {
            parent[u] = v;
            v = mate[u];
            if (parity[v] == 1) parity[v] = 0, bfs_queue.push(v);
            blossom[u] = blossom[v] = p;
            u = parent[v];
        }
    }

    bool bfs(int root) {
        ranges::fill(parity, -1);
        ranges::fill(parent, -1);
        iota(begin(blossom), end(blossom), 0);

        bfs_queue = queue<int>();
        bfs_queue.push(root);
        parity[root] = 0;

        while (!bfs_queue.empty()) {
            int u = bfs_queue.front(); bfs_queue.pop();
            for (auto v : adj[u]) {
                if (parity[v] == -1) {
                    parity[v] = 1;
                    parent[v] = u;
                    if (mate[v] == -1) {
                        augment(v);
                        return true;
                    }
                    parity[mate[v]] = 0;
                    bfs_queue.push(mate[v]);
                } else if (parity[v] == 0 && blossom[u] != blossom[v]) {
                    int p = lca(blossom[u], blossom[v]);
                    merge(u, v, p), merge(v, u, p);
                }
            }
        }
        return false;
    }

    int solve() {
        for (int i = 0; i < n; ++i)
            if (mate[i] == -1)
                size += bfs(i);
        return size;
    }

    vector<int> mate, parity, blossom, parent, last;
    int size = 0, timer = 0, n;
    vector<vector<int>> adj;
    queue<int> bfs_queue;
};

const int N = 300000, K = 601;

int a[N];

vector<array<int, 4>> or_edges[K];
bool visited_edge[N];

bool paired[K], exposed[K], visited[K];
int color[K];

pair<int, int> and_edges[K][K];

void dfs_color(int u, int x) {
    color[u] = x;
    for (auto [v, id, l, r] : or_edges[u])
        if (color[v] == 0)
            dfs_color(v, x);
}

bool dfs_solve(int u) {
    bool covered = false;
    visited[u] = true;
    for (auto [v, id, l, r] : or_edges[u]) {
        if (visited_edge[id]) continue;
        visited_edge[id] = true;

        if (!visited[v]) {
            if (dfs_solve(v)) {
                if (!covered) {
                    covered = true;
                    a[l] = u;
                }
            } else a[r] = v;
        } else if (!covered) {
            covered = true;
            a[l] = u;
        }
    }
    return covered;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k = *ranges::max_element(a), m = 0;

    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
            and_edges[i][j] = {-1, -1};

    for (int i = -1, j = i; i < n; i = j) {
        do ++j; while (j < n && a[j] == 0);
        int zeroes = j - i - 1;
        
        vector<pair<int, int>> endpoints;
        if (i >= 0) endpoints.push_back({a[i], i + 1});
        if (j < n) endpoints.push_back({a[j], j - 1});

        if (!endpoints.empty()) {
            auto [al, l] = endpoints[0];
            auto [ar, r] = endpoints.back();

            if (zeroes % 2 == 1 || (zeroes == 0 && ssize(endpoints) == 2 && al == ar)) {
                or_edges[al].push_back({ar, m, l, r});
                or_edges[ar].push_back({al, m++, r, l});
            } else if (zeroes > 0) {
                and_edges[al][ar] = {l, r};
                and_edges[ar][al] = {r, l};
            }
        }
    }

    for (int i = 1; i <= k; ++i) {
        if (color[i] == 0) {
            dfs_color(i, i);

            int vertices = 0, edges = 0;
            for (int j = 1; j <= k; ++j) {
                if (color[j] == i) {
                    edges += (int) ssize(or_edges[j]);
                    ++vertices;
                }
            }
            edges /= 2;

            exposed[i] = (edges == vertices - 1);
        }
    }

    maximum_matching blossom(k + 1);
    set<pair<int, int>> edges;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (and_edges[i][j].first >= 0) {
                int u = color[i], v = color[j];
                if (exposed[u] && exposed[v] && !edges.contains({u, v})) {
                    blossom.add_edge(u, v);
                    edges.insert({u, v}), edges.insert({v, u});
                }
            }
        }
    }
    blossom.solve();

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (and_edges[i][j].first >= 0) {
                int u = color[i], v = color[j];
                if (exposed[u] && exposed[v] && blossom.mate[u] == v) {
                    auto [l, r] = and_edges[i][j];
                    a[l] = i, a[r] = j;
                    dfs_solve(i), dfs_solve(j);
                    exposed[u] = exposed[v] = false;
                }
            }
        }
    }

    for (int i = 1; i <= k; ++i) {
        if (color[i] == i && blossom.mate[i] == -1) {
            dfs_solve(i);
        }
    }

    set<int> values;
    for (int i = 1; i <= n; ++i) values.insert(i);
    for (int i = 0; i < n; ++i) values.erase(a[i]);

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            int v = *values.begin();
            values.erase(values.begin());
            a[i] = v;
            if (i + 1 < n && a[i + 1] == 0)
                a[i + 1] = v, ++i;
        }
    }

    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";
}