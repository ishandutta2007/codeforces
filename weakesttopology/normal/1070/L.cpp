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

template<int N> struct XORBasis
{
private:
    using V = bitset<N>;
    array<V, N> basis, alpha;
    int dim = 0;
    auto reduce(V& x) const
    {
        V coef;
        for (int i = N - 1; i >= 0 && x.any(); --i)
        {
            if (x[i] == 0) continue;
            if (basis[i] == 0) return pair(i, coef);
            x ^= basis[i], coef ^= alpha[i];
        }
        return pair(-1, coef);
    }
public:
    bool insert(V x)
    {
        auto [i, coef] = reduce(x);
        if (i == -1) return false;
        basis[i] = x, dim += 1;
        alpha[i] = coef;
        alpha[i][dim - 1] = 1;
        return true;
    }
    auto solve(V x) const
    {
        auto [i, coef] = reduce(x);
        return pair(i == -1, coef);
    }
    int dimension() const { return dim; }
};

void solve()
{
    int n, m; cin >> n >> m;

    vector E(n, vector(0, 0));

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    constexpr int N = 2000;

    XORBasis<N> basis;

    bitset<N> b;

    vector independent(0, 0);

    for (int u = 0; u < n; ++u)
    {
        bitset<N> col;

        for (auto v : E[u]) col[v] = 1;

        if (size(E[u]) % 2) col[u] = b[u] = 1;

        if (basis.insert(col)) independent.push_back(u);
    }

    auto [good, x] = basis.solve(b);

    vector ans(n, 0);

    for (auto i = 0; i < size(independent); ++i)
        ans[independent[i]] = x[i];

    cout << (1 + x.any()) << endl;

    for (int u = 0; u < n; ++u)
        cout << ans[u] + 1 << " ";
    cout << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}