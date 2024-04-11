#include <bits/stdc++.h>
using namespace std;

const int N = 300000, L = bit_width((unsigned) N);

vector<pair<int, int>> adj[N];
int par[N], sub[N], preorder[N], postorder[N], head[N];
int sparse[L][N];

void dfs_init(int u) {
    sub[u] = 1;
    for (auto [c, w] : adj[u]) {
        adj[c].erase(ranges::find(adj[c], make_pair(u, w)));
        par[c] = u;
        dfs_init(c);
        sub[u] += sub[c];
    }
}

void dfs_hld(int u) {
    static int t = 0;

    preorder[u] = t++;
    ranges::sort(adj[u], [&](auto a, auto b) { return sub[a.first] > sub[b.first]; });
    for (auto [c, w] : adj[u]) {
        head[c] = c == adj[u][0].first ? head[u] : c;
        dfs_hld(c);
        sparse[0][preorder[c]] = w;
    }
    postorder[u] = t;
}

int range_max(int a, int b) {
    if (a == b) return -1;
    int l = bit_width((unsigned) (b - a)) - 1;
    return max(sparse[l][a], sparse[l][b - (1 << l)]);
}

pair<int, int> path_max(int u, int v) {
    int max_weight = -1;

    while (head[u] != head[v]) {
        if (preorder[u] > preorder[v]) swap(u, v);
        max_weight = max(max_weight, range_max(preorder[head[v]], preorder[v] + 1));
        v = par[head[v]];
    }

    if (preorder[u] > preorder[v]) swap(u, v);
    max_weight = max(max_weight, range_max(preorder[u] + 1, preorder[v] + 1));

    return {max_weight, u};
}

pair<int, int> combine_graph(pair<int, int> l, pair<int, int> r) {
    if (l.second == -1) return r;
    if (r.second == -1) return l;

    pair<int, int> result = path_max(l.second, r.second);
    result.first = max({result.first, l.first, r.first});

    return result;
}

struct segtree {
    struct node {
        node *left, *right;

        pair<int, int> cur_graph, full_graph;
        int tag;

        node(int l, int r) {
            cur_graph = {-1, -1};
            tag = 0;

            if (r - l > 1) {
                int m = (l + r) / 2;
                left = new node(l, m);
                right = new node(m, r);
                full_graph = combine_graph(left->full_graph, right->full_graph);
            } else {
                full_graph = {-1, l};
            }
        }

        void update(int a, int b, int x, int l, int r) {
            if (a <= l && r <= b) apply(x);
            else if (b <= l || r <= a) return;
            else {
                push();
                int m = (l + r) / 2;
                left->update(a, b, x, l, m);
                right->update(a, b, x, m, r);
                pull();
            }
        }

        void apply(int x) {
            cur_graph = x == 1 ? full_graph : make_pair(-1, -1);
            tag = x;
        }

        void push() {
            if (tag != 0) {
                left->apply(tag), right->apply(tag);
                tag = 0;
            }
        }

        void pull() {
            cur_graph = combine_graph(left->cur_graph, right->cur_graph);
        }
    };

    segtree(int n) : n(n) {
        root = new node(0, n);
    }

    pair<int, int> operator()() {
        return root->cur_graph;
    }

    void update(int a, int b, int x) {
        root->update(a, b, x, 0, n);
    }

    node *root;
    int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w; --u, --v;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs_init(0);
    dfs_hld(0);

    for (int i = 1; i < (int) bit_width((unsigned) n); ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }

    segtree meteor_town(n);

    while (q--) {
        int type; cin >> type;

        if (type == 1 || type == 2) {
            int l, r; cin >> l >> r; --l;
            meteor_town.update(l, r, type);
        } else {
            int x; cin >> x; --x;
            cout << combine_graph(meteor_town(), {-1, x}).first << "\n";
        }
    }
}