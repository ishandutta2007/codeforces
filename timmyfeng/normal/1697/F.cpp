#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 2e4 * 11;

vector<int> adj[N];

void add_clause(int a, bool xa, int b, bool xb) {
    adj[2 * a + !xa].push_back(2 * b + xb);
    adj[2 * b + !xb].push_back(2 * a + xa);
}

int preorder[N], color[N];

void dfs(int u) {
    static int time = 0, components = 0, low[N];
    static vector<int> node_stack;

    node_stack.push_back(u);
    preorder[u] = low[u] = ++time;
    for (auto c : adj[u]) {
        if (!preorder[c]) {
            dfs(c);
            low[u] = min(low[u], low[c]);
        } else if (!color[c]) {
            low[u] = min(low[u], low[c]);
        }
    }

    if (low[u] == preorder[u]) {
        int v = -1;
        ++components;
        while (v != u) {
            v = node_stack.back();
            node_stack.pop_back();
            color[v] = components;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        fill(adj, adj + 2 * (k + 1) * n, vector<int>());
        fill(preorder, preorder + 2 * (k + 1) * n, 0);
        fill(color, color + 2 * (k + 1) * n, 0);

        for (int i = 0; i < n; ++i) {
            add_clause((k + 1) * i + 0, false, (k + 1) * i + 0, false);
            add_clause((k + 1) * i + k, true, (k + 1) * i + k, true);
            for (int x = 0; x < k; ++x)
                add_clause((k + 1) * i + x, false, (k + 1) * i + x + 1, true);
        }

        for (int i = 1; i < n; ++i) {
            for (int x = 0; x <= k; ++x) {
                add_clause((k + 1) * (i - 1) + x, true, (k + 1) * i + x, false);
            }
        }

        for (int i = 0; i < m; ++i) {
            int type; cin >> type;
            if (type == 1) {
                int a, x; cin >> a >> x; --a;
                add_clause((k + 1) * a + x - 1, true, (k + 1) * a + x, false);
            } else if (type == 2) {
                int a, b, x; cin >> a >> b >> x; --a, --b;
                for (int y = 0; y < x; ++y) {
                    if (y <= k && x - 1 - y <= k)
                        add_clause((k + 1) * a + y, true, (k + 1) * b + x - 1 - y, true);
                }
            } else if (type == 3) {
                int a, b, x; cin >> a >> b >> x; --a, --b;
                for (int y = 0; y < x; ++y) {
                    if (y <= k && x - 1 - y <= k)
                        add_clause((k + 1) * a + y, false, (k + 1) * b + x - 1 - y, false);
                }
            }
        }

        for (int i = 0; i < 2 * (k + 1) * n; ++i) {
            if (!preorder[i]) dfs(i);
        }

        vector<int> answer(n);
        bool satisfiable = true;
        for (int i = 0; i < (k + 1) * n; ++i) {
            satisfiable &= color[2 * i] != color[2 * i + 1];
            if (color[2 * i] < color[2 * i + 1]) ++answer[i / (k + 1)];
        }

        if (satisfiable) {
            for (auto i : answer) cout << i << " ";
            cout << "\n";
        } else cout << -1 << "\n";
    }
}