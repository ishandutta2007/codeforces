#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

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
    bool insert(V x) // returns true if dimension increases
    {
        auto [i, coef] = reduce(x);
        if (i == -1) return false;
        basis[i] = x, dim += 1;
        alpha[i] = coef;
        alpha[i][dim - 1] = 1;
        return true;
    }
    auto solve(V x) const // returns coefficients of inserted vectors
    {
        auto [i, coef] = reduce(x);
        return pair(i == -1, coef);
    }
    V combination(V coef) const // coefficients of current basis
    {
        V res;
        for (int i = 0; i < N; ++i) if (coef[i]) res ^= basis[i];
        return res;
    }
    int dimension() const { return dim; }
};

const ll MOD = 1e9 + 7;

ll power(ll x, ll p)
{
    ll res = 1;
    while (p > 0)
    {
        if (p & 1) res = (res * x) % MOD;
        x = (x * x) % MOD, p >>= 1;
    }
    return res;
}

int main()
{ _
    int n, q; cin >> n >> q;

    const int N = 20;

    vector<XORBasis<N>> basis(n);

    XORBasis<N> cur;

    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        cur.insert(a);
        basis[i] = cur;
    }

    for (int z = 0; z < q; ++z)
    {
        int l, x; cin >> l >> x; --l;

        auto [b, coef] = basis[l].solve(x);

        ll ans = 0LL;

        if (b) ans += power(2, l + 1 - basis[l].dimension());

        cout << ans << endl;
    }

    exit(0);
}