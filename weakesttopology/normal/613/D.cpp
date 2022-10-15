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
        L[u] = ct++;
        for (int v : E[u]) if (v != p) dfs(v, u);
        R[u] = ct - 1;
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
        for (int i = K; i >= 0; --i) if (!is_ancestor(up[u][i], v)) u = up[u][i];
        return up[u][0];
    }
};

int main()
{ _
    int n; cin >> n;

    vector E(n, vector(0, 0));

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    LCA<17> lca(E, 0);

    const auto& tin = lca.L, tout = lca.R;

    vector parent(n, 0);

    for (int u = 0; u < n; ++u) parent[u] = lca.up[u][0];

    auto cmp = [&](int u, int v) { return tin[u] < tin[v]; };

    vector V(0, 0), mark(n, 0);
    vector F(n, vector(0, 0));

    auto build = [&]()
    {
        sort(all(V), cmp);

        for (int k = size(V), i = 1; i < k; ++i)
            V.push_back(lca.query(V[i], V[i - 1]));

        sort(all(V), cmp), V.erase(unique(all(V)), end(V));

        int root = V[0];

        stack<int> stk; stk.push(root);

        for (int i = 1; i < size(V); ++i)
        {
            int v = V[i];
            while (tout[stk.top()] < tin[v]) stk.pop();
            F[stk.top()].push_back(v);
            stk.push(v);
        }

        return root;
    };

    function<complex<int>(int)> solve = [&](int u)
    {
        complex<int> res = 0;

        for (auto v : F[u]) res += solve(v);

        F[u].clear();

        if (mark[u]) res = complex<int>(1, res.real() + res.imag());
        else if (res.real() > 1) res = complex<int>(0, res.imag() + 1);

        return res;
    };

    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int k; cin >> k;

        for (int j = 0; j < k; ++j)
        {
            int u; cin >> u; --u;
            V.push_back(u);
            mark[u] = 1;
        }

        sort(all(V));

        bool good = true;

        for (auto u : V) if (int v = parent[u]; v != u)
        {
            if (mark[v])
            {
                good = false;
                break;
            }
        }

        int ans = -1;

        if (good) ans = solve(build()).imag();

        cout << ans << endl;

        for (auto u : V) mark[u] = 0;

        V.clear();
    }

    exit(0);
}