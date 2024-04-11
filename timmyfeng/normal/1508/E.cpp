#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

int a[N], in[N], depth[N], t;
vector<int> adj[N];
long long ans;
bool pre[N];

void dfs_root(int u) {
    sort(adj[u].begin(), adj[u].end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    in[u] = ++t;

    for (auto c : adj[u]) {
        adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
        dfs_root(c);
    }
}

void dfs_pre(int u) {
    if (++t != a[u]) {
        cout << "NO\n";
        exit(0);
    }

    pre[u] = true;
    for (auto c : adj[u]) {
        if (a[c] > a[u]) {
            dfs_pre(c);
        }
    }
}

void dfs_post(int u) {
    for (auto c : adj[u]) {
        depth[c] = depth[u] + 1;
        dfs_post(c);
    }

    ++t;
    if (!pre[u]) {
        if (t != a[u]) {
            cout << "NO\n";
            exit(0);
        }
        ans += depth[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_root(0);

    int i = 0;
    for (int j = 1; j < n; ++j) {
        if (!adj[j].empty() && a[j] < a[adj[j].back()]) {
            if (a[j] < a[i]) {
                i = j;
            }
        }
    }

    if (i > 0) {
        while (true) {
            int j = 0;
            while (j < (int) adj[i].size() && a[i] > a[adj[i][j]]) {
                ++j;
            }

            if (j == (int) adj[i].size()) {
                break;
            }

            swap(a[i], a[adj[i][j]]);
            i = adj[i][j];
            --ans;
        }
    }

    t = a[0] - 1;
    dfs_pre(0);

    t = 0;
    dfs_post(0);

    cout << "YES\n";
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << in[i] << " ";
    }
    cout << "\n";
}