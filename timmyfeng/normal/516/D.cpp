#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
    T, __gnu_pbds::null_type, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

vector<array<long long, 2>> adj[N];
long long dist[N][2];

void update(int u, long long x) {
    if (x > dist[u][0]) {
        dist[u][1] = dist[u][0];
        dist[u][0] = x;
    } else if (x > dist[u][1]) {
        dist[u][1] = x;
    }
}

void dfs_pull(int u, int p = -1) {
    for (auto [c, w] : adj[u]) {
        if (c != p) {
            dfs_pull(c, u);
            update(u, dist[c][0] + w);
        }
    }
}

void dfs_push(int u, int p = -1) {
    for (auto [c, w] : adj[u]) {
        if (c != p) {
            update(c, dist[u][0] == dist[c][0] + w ? dist[u][1] + w : dist[u][0] + w);
            dfs_push(c, u);
        }
    }
}

const int Q = 50;

long long diff[Q];
int ans[Q], q;

ordered_set<array<long long, 2>> * dfs_dsu(int u, int p = -1) {
    auto me = new ordered_set<array<long long, 2>>();
    for (auto [c, w] : adj[u]) {
        if (c != p) {
            auto son = dfs_dsu(c, u);
            if (me->size() < son->size()) {
                swap(me, son);
            }
            for (auto x : *son) {
                me->insert(x);
            }
            delete son;
        }
    }
    me->insert({dist[u][0], u});
    for (int i = 0; i < q; ++i) {
        ans[i] = max(ans[i], (int) me->order_of_key({dist[u][0] + diff[i] + 1, 0}));
    }
    return me;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs_pull(0);
    dfs_push(0);

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i][0] < dist[root][0]) {
            root = i;
        }
    }

    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> diff[i];
    }

    dfs_dsu(root);

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}