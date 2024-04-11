#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll modpow(ll x, ll p, ll mod) {
    ll res = 1;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

auto sieve(int N) {
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

// K > floor(log(tree height))
template<int K>
struct LCA {
    const vector<vector<int>>& E;
    const int n;
    vector<int> L, R;
    vector<array<int, K>> up;
    int timer = 0;
    void dfs(int u, int p) {
        up[u][0] = p;
        for (int i = 1; i < K; ++i) up[u][i] = up[up[u][i-1]][i-1];
        L[u] = timer;
        for (int v : E[u]) if (v != p) dfs(v, u);
        R[u] = timer++;
    }
    LCA(const auto& E, int root) : E(E), n((int)size(E)), L(n), R(n), up(n) {
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
};

template<typename T>
struct BIT {
    int n;
    vector<T> ft;
    BIT(int n) : n(n), ft(n + 1, 0) {}
    void update(int p, T value) {
        for (p += 1; p >= 1; p -= p & -p) ft[p] += value;
    };
    void update(int l, int r, T value) {
        update(r, value), update(l - 1, -value);
    }
    T query(int p) {
        T res = 0;
        for (p += 1; p <= n; p += p & -p) res += ft[p];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    int N = 1e7;
    auto [lp, pr] = sieve(N);

    vector<int> a(n);
    map<int, vector<pair<int, int>>> Q, V;
    for (int u = 0; u < n; ++u) {
        cin >> a[u];
        for (int x = a[u], p = lp[x]; x > 1; p = lp[x]) {
            for (int e = 1; lp[x] == p; x /= p, e += 1) {
                V[p].emplace_back(e, u);
            }
        }
    }

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int z = 0; z < q; ++z) {
        auto& [u, v] = queries[z];
        int x;
        cin >> u >> v >> x;
        --u, --v;
        for (int p = lp[x]; x > 1; p = lp[x]) {
            int e = 0;
            while (lp[x] == p) e += 1, x /= p;
            Q[p].emplace_back(e, z);
        }
    }
    constexpr ll mod = 1e9 + 7;
    vector<ll> res(n, 1);

    BIT<int> bit(n);
    LCA<20> lca(E, 0);

    for (auto& [p, vecV] : V) sort(all(vecV));
    for (auto& [p, vecQ] : Q) {
        sort(all(vecQ));
        const auto& vecV = V[p];
        int k = (int)size(vecV), j = 0;
        for (auto [e, z] : vecQ) {
            while (j < k && vecV[j].first <= e) {
                int v = vecV[j].second;
                bit.update(lca.L[v], lca.R[v], 1);
                j += 1;
            }
            int f = 0;
            auto [u, v] = queries[z];
            for (auto w : {u, v}) f += bit.query(lca.R[w]);
            int w = lca.lca(u, v);
            f -= 2 * bit.query(lca.R[w]);
            for (int x = a[w]; x % p == 0 && e > 0; --e, x /= p, ++f);
            res[z] = res[z] * modpow(p, f, mod) % mod;
        }
        while (j > 0) {
            --j;
            int v = vecV[j].second;
            bit.update(lca.L[v], lca.R[v], -1);
        }
    }

    for (int z = 0; z < q; ++z) {
        cout << res[z] << endl;
    }


    exit(0);
}