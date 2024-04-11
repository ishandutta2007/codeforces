#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// K >= floor(log(height))

template<int K>
struct LCA
{
    const vector<vector<int>>& E;
    const int n;
    vector<int> L, R, h;
    vector<array<int, K + 1>> up;
    int ct = 0;
    void dfs(int u, int p)
    {
        h[u] = h[p] + 1, up[u][0] = p;
        for (int i = 1; i <= K; ++i) up[u][i] = up[up[u][i-1]][i-1];
        L[u] = ct;
        for (int v : E[u]) if (v != p) dfs(v, u);
        R[u] = ct++;
    }
    LCA(const auto& E, int root) : E(E), n(size(E)), L(n), R(n), h(n), up(n)
    {
        dfs(root, root);
    }
    bool is_ancestor(int u, int v) const
    {
        return L[u] <= L[v] && R[v] <= R[u];
    }
    int query(int u, int v) const
    {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = K; i >= 0; --i)
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        return up[u][0];
    }
    int query(int u, int v, int root) const
    {
        int w[3] = { query(u, v), query(u, root), query(v, root) };
        if (w[0] == w[1]) return w[2];
        else if (w[0] == w[2]) return w[1];
        else return w[0];
    }
    int distance(int u, int v) const
    {
        int w = query(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};

int main()
{ _
    int n, q;
    cin >> n >> q;

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    constexpr int K = 17;
    LCA<K> lca(E, 0);
    for (int u = 0; u < n; ++u) lca.h[u] -= 1;

    vector<ll> cnt(n, -1), weight(n), cnt_up(n, -1), weight_up(n);

    auto dfs = [&](auto& self, int u) -> void
    {
        cnt[u] = 1, weight[u] = 0;
        for (auto v : E[u]) if (cnt[v] == -1)
        {
            self(self, v);
            weight[u] += weight[v] + cnt[v], cnt[u] += cnt[v];
        }
    };
    dfs(dfs, 0);

    auto solve_up = [&](auto& self, int u, ll num, ll sum) -> void
    {
        cnt_up[u] = num, weight_up[u] = sum;
        for (auto v : E[u]) if (cnt_up[v] == -1)
        {
            ll diff_cnt = cnt[u] - cnt[v];
            ll diff_weight = weight[u] - (weight[v] + cnt[v]);
            self(self, v, num + diff_cnt, num + sum + diff_weight + diff_cnt);
        }
    };
    solve_up(solve_up, 0, 0, 0);

    cout << setprecision(10) << fixed;

    for (int z = 0; z < q; ++z)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;

        double res = 0;

        if (lca.is_ancestor(v, u)) swap(u, v);
        if (lca.is_ancestor(u, v))
        {
            int w = v;
            for (int k = K; k >= 0; --k)
            {
                if (not lca.is_ancestor(lca.up[w][k], u)) w = lca.up[w][k];
            }

            res += cnt[v] * (weight_up[u] + weight[u] - (weight[w] + cnt[w]));
            res += (cnt_up[u] + cnt[u] - cnt[w]) * weight[v];

            res /= (cnt_up[u] + cnt[u] - cnt[w]) * cnt[v];
            res += 1 + lca.h[v] - lca.h[u];
        }
        else
        {
            res += cnt[u] * weight[v] + cnt[v] * weight[u];
            res /= cnt[u] * cnt[v];
            res += 1 + lca.distance(u, v);
        }

        cout << res << endl;
    }

    exit(0);
}