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
    array<bitset<N>, N> basis, alpha;
    int dim = 0;

    auto reduce(bitset<N>& x) const
    {
        bitset<N> coef;
        for (int i = N - 1; i >= 0 && x.any(); --i)
        {
            if (x[i] == 0) continue;
            if (basis[i] == 0) return pair(i, coef);
            x ^= basis[i], coef ^= alpha[i];
        }
        return pair(-1, coef);
    }

    bool insert(bitset<N> x)
    {
        auto [i, coef] = reduce(x);
        if (i == -1) return false;
        basis[i] = x, dim += 1;
        alpha[i] = coef;
        alpha[i][dim - 1] = 1;
        return true;
    }

    auto solve(bitset<N> x)
    {
        auto [i, coef] = reduce(x);
        return pair(i == -1, coef);
    }

};

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main()
{ _
    ll x; cin >> x;

    constexpr int N = 40;

    using B = bitset<N>;

    XORBasis<N> basis;

    uniform_int_distribution<ll> unif(1LL, 1LL << N);

    auto combination = [&](B coef)
    {
        B res;
        for (int i = 0; i < N; ++i)
            if (coef[i]) res ^= basis.basis[i];
        return res.to_ullong();
    };

    vector independent(1, x); basis.insert(x);

    vector op(0, tuple(0LL, 0LL, 0));

    auto putop = [&](ll x)
    {
        auto coef = basis.solve(x).second;

        ll cur = 0;

        for (int i = 0; i < N; ++i) if (coef[i])
        {
            if (cur) op.emplace_back(cur, independent[i], 0);
            cur ^= independent[i];
        }
    };

    while (not basis.solve(1).first)
    {
        ll u = combination(unif(rng)), v = combination(unif(rng));

        if (u == 0 || v == 0 || u + v >= 1LL << N) continue;

        if (not basis.solve(u + v).first)
        {
            putop(u), putop(v);
            op.emplace_back(u, v, 1);
            basis.insert(u + v);
            independent.push_back(u + v);
        }
    }

    putop(1);

    cout << size(op) << endl;
    for (auto [u, v, t] : op)
        cout << u << (t ? " + " : " ^ ") << v << endl;

    exit(0);
}