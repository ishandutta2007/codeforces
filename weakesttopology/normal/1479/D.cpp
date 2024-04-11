#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// K > floor(log(tree height))
template<int K>
struct LCA {
    const vector<vector<int>>& E;
    int n;
    vector<int> L, R, inv, h;
    vector<array<int, K>> up;
    int timer = 0;
    void dfs(int u, int p) {
        up[u][0] = p;
        for (int i = 1; i < K; ++i) up[u][i] = up[up[u][i-1]][i-1];
        inv[L[u] = timer++] = u;
        for (int v : E[u]) if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
        R[u] = timer - 1;
    }
    LCA(const auto& E, int root) : E(E), n((int)size(E)), L(n), R(n), inv(n), h(n), up(n) {
        dfs(root, root);
    }
    bool is_ancestor(int u, int v) const {
        return L[u] <= L[v] && R[v] <= R[u];
    }
    int lca(int u, int v) const {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = K - 1; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};
struct TreeDecomposition {
    const vector<vector<int>>& E;
    const int n, root, K;
    vector<int> block, p, L, R;
    int num_blocks = 0;
    void mark(const vector<int>& S) {
        for (auto u : S) {
            block[u] = num_blocks;
        }
        ++num_blocks;
    }
    int timer = 0;
    pair<int, vector<int>> decompose(int u) {
        L[u] = timer++;
        int hmax = 0;
        vector<int> S;
        for (auto v : E[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            auto [h, R] = decompose(v);
            if (size(R) > size(S)) swap(S, R);
            S.insert(end(S), begin(R), end(R));
            if (hmax + h > K) {
                mark(S);
                S.clear();
                hmax = 0;
            }
            else hmax = max(hmax, h);
        }
        R[u] = timer - 1;
        S.push_back(u);
        return {hmax + 1, S};
    }
    // O(n * K)
    TreeDecomposition(const vector<vector<int>>& E, int root, int K) : E(E), n((int)size(E)), root(root), K(K), block(n), p(n, -1), L(n), R(n) {
        auto [h, S] = decompose(root);
        if (not empty(S)) mark(S);
    }
    bool is_ancestor(int u, int v) const {
        return L[u] <= L[v] && L[v] <= R[u];
    }
    template<typename Update>
    void traverse(array<int, 2> P, Update&& update) const {
        for (int t : {0, 1}) {
            while (not is_ancestor(P[t], P[t ^ 1])) {
                update(P[t]);
                P[t] = p[P[t]];
            }
        }
    }
    // O(n^2 / K + size(Q) * K)
    template<typename Evaluate, typename Update>
    void run(const vector<array<int, 2>>& Q, Evaluate&& evaluate, Update&& update) const {
        vector<int> Z(size(Q));
        iota(begin(Z), end(Z), 0);
        auto key = [&](int i) { return pair<int, int>(block[Q[i][0]], L[Q[i][1]]); };
        sort(begin(Z), end(Z), [&](int i, int j) { return key(i) < key(j); });
        array<int, 2> P = {0, 0};
        for (auto z : Z) {
            for (int t : {0, 1}) {
                traverse({P[t], Q[z][t]}, update);
                P[t] = Q[z][t];
            }
            evaluate(z);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int u = 0; u < n; ++u) {
        cin >> a[u];
        --a[u];
    }
    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    vector<array<int, 2>> P(q);
    vector<int> l(q), r(q);
    for (int z = 0; z < q; ++z) {
        for (int t : {0, 1}) {
            cin >> P[z][t];
            --P[z][t];
        }
        cin >> l[z] >> r[z];
        --l[z], --r[z];
    }
    const int K = 3 * (int)sqrt(n);
    vector<int> blocksum(n), freq(n);
    auto update = [&](int u) {
        int x = a[u];
        freq[x] ^= 1;
        blocksum[x / K] += freq[x] - !freq[x];
    };
    vector<int> c(q, -2);
    LCA<20> lca(E, 0);
    auto evaluate = [&](int z) {
        int u = lca.lca(P[z][0], P[z][1]);
        update(u);
        for (int i = l[z]; i % K && i <= r[z]; ++i) {
            if (freq[i]) c[z] = i;
        }
        for (int i = r[z]; i >= l[z]; --i) {
            if (freq[i]) c[z] = i;
            if (i % K == 0) break;
        }
        for (int k = (l[z] + K - 1) / K; k < r[z] / K; ++k) {
            if (blocksum[k]) {
                int i = k * K;
                while (freq[i] == 0) ++i;
                c[z] = i;
                break;
            }
        }
        update(u);
    };
    TreeDecomposition td(E, 0, K);
    td.run(P, evaluate, update);
    for (int z = 0; z < q; ++z) {
        cout << c[z] + 1 << '\n';
    }
    exit(0);
}
//