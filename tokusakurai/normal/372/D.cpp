#include <bits/stdc++.h>
using namespace std;

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<vector<int>> par; // par[i][j] := j2^i
    vector<int> depth;
    int height;

    vector<int> vs, ids;
    set<int> s;
    int Steiner_size;

    Graph(int n) : es(n), n(n), m(0), depth(n), ids(n), Steiner_size(0) {
        height = 1;
        while ((1 << height) < n) height++;
        par.assign(height, vector<int>(n));
    }

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void prepare(int now, int pre = -1) {
        if (pre == -1) depth[now] = 0;
        par[0][now] = pre;
        ids[now] = vs.size();
        vs.push_back(now);
        for (auto &e : es[now]) {
            if (e.to != pre) {
                depth[e.to] = depth[now] + 1;
                prepare(e.to, now);
            }
        }
    }

    void build(int root = 0) { // root
        prepare(root);
        for (int j = 0; j < height - 1; j++) {
            for (int i = 0; i < n; i++) {
                if (par[j][i] == -1) {
                    par[j + 1][i] = -1;
                } else {
                    par[j + 1][i] = par[j][par[j][i]];
                }
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int D = depth[u] - depth[v];
        for (int i = 0; i < height; i++) {
            if ((D >> i) & 1) u = par[i][u];
        }
        if (u == v) return u;
        for (int i = height - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }

    int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

    int insert(int x) {
        if (s.count(ids[x])) return Steiner_size;
        if (s.empty()) {
            Steiner_size++;
        } else {
            auto l = s.upper_bound(ids[x]);
            auto r = l--;
            if (r == begin(s) || r == end(s)) l = begin(s), r = end(s), r--;
            Steiner_size += (dist(vs[*l], x) + dist(x, vs[*r]) - dist(vs[*l], vs[*r])) / 2;
        }
        s.insert(ids[x]);
        return Steiner_size;
    }

    int erase(int x) {
        if (!s.count(ids[x])) return Steiner_size;
        s.erase(ids[x]);
        if (s.empty()) {
            Steiner_size--;
        } else {
            auto l = s.upper_bound(ids[x]);
            auto r = l--;
            if (r == begin(s) || r == end(s)) l = begin(s), r = end(s), r--;
            Steiner_size -= (dist(vs[*l], x) + dist(x, vs[*r]) - dist(vs[*l], vs[*r])) / 2;
        }
        return Steiner_size;
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    Graph G(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }

    G.build();

    int ans = 0;

    int r = 0, si = 0;
    for (int l = 0; l < N; l++) {
        while (r <= N && si <= K) {
            if (r < N) si = G.insert(r);
            // cout << l + 1 << ' ' << r + 1 << ' ' << si << '\n';
            r++;
        }
        ans = max(ans, r - l - 1);
        si = G.erase(l);
    }

    cout << ans << '\n';
}