#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

class LCA
{
private:
    const vector<vector<int>>& E;
    const int n, lg;
    vector<int> L, R, h;
    vector<vector<int>> up;
    void dfs(int u, int p)
    {
        h[u] = h[p] + 1, up[u][0] = p;
        for (int i = 1; i < lg; ++i)
            up[u][i] = up[up[u][i-1]][i-1];
        static int ct = 0;
        L[u] = ct;
        for (int v : E[u])
            if (v != p) dfs(v, u);
        R[u] = ct++;
    }
public:
    LCA(const vector<vector<int>>& E, int root) : E(E), n(sz(E)), lg(32 - __builtin_clz(n))
    {
        L.assign(n, 0), R.assign(n, 0), h.assign(n, -1);
        up.assign(n, vector<int>(lg));
        dfs(root, root);
    }
    bool is_ancestor(int u, int v) const
    {
        return L[u] <= L[v] && R[v] <= R[u];
    }
    int lca(int u, int v) const
    {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = lg - 1; i >= 0; --i)
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
    int distance(int u, int v) const
    {
        int w = lca(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};

int main()
{ _
    int q; cin >> q;
    int n = 2 * q + 4;

    vector E(n, vector(0, 0));
    for (int i = 1; i < 4; ++i)
        E[0].push_back(i), E[i].push_back(0);

    for (int j = 0; j < q; ++j)
    {
        int v; cin >> v; --v;
        for (int t = 0; t < 2; ++t)
            E[v].push_back(4 + 2 * j + t), E[4 + 2 * j + t].push_back(v);
    }
    LCA lca(E, 0);

    int x = 1, y = 2, ans = 2;

    auto update = [&](int v)
    {
        tie(ans, x, y) = max({tuple(lca.distance(x, v), x, v), tuple(lca.distance(y, v), y, v), tuple(ans, x, y)});
    };

    for (int j = 0; j < q; ++j)
    {
        for (int t = 0; t < 2; ++t)
            update(4 + 2 * j + t);
        cout << ans << endl;
    }

    exit(0);
}