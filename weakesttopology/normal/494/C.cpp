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

template<int N>
struct Distribution
{
    int offset = 0;
    array<double, N> p;

    Distribution()
    {
        fill(all(p), 0.0);
        p[0] = 1.0;
    }

    Distribution& operator+=(double add)
    {
        for (int k = N - 1; k >= 0; --k)
        {
            p[k] *= (1 - add);

            if (k > 0) p[k] += add * p[k - 1];
        }

        return *this;
    }

    Distribution operator*(const Distribution& rhs) const
    {
        const auto& lhs = *this;

        Distribution res; fill(all(res.p), 0.0);

        res.offset = max(lhs.offset, rhs.offset);

        double lhs_prefix = 0.0, rhs_prefix = 0.0;

        int L = 0, R = 0;

        while (lhs.offset + L < res.offset && L < N)
            lhs_prefix += lhs.p[L++];

        while (rhs.offset + R < res.offset && R < N)
            rhs_prefix += rhs.p[R++];

        for (int k = 0; k < N; ++k)
        {
            if (L < N) res.p[k] += lhs.p[L] * rhs_prefix;

            if (R < N) res.p[k] += rhs.p[R] * lhs_prefix;

            if (L < N && R < N) res.p[k] += lhs.p[L] * rhs.p[R];

            if (L < N) lhs_prefix += lhs.p[L++];

            if (R < N) rhs_prefix += rhs.p[R++];
        }

        return res;
    }
};

int main()
{ _
    int n, q; cin >> n >> q;

    vector a(n, 0);

    for (int i = 0; i < n; ++i) cin >> a[i];

    vector V(q, tuple(0, 0, 0.0));

    for (auto& [l, r, p] : V)
    {
        cin >> l >> r >> p; --l, --r;
    }

    auto cmp = [&](auto u, auto v)
    {
        auto [ul, ur, up] = u;
        auto [vl, vr, vp] = v;
        if (ul != vl) return ul < vl;
        return ur > vr;
    };

    sort(all(V), cmp);

    V.emplace_back(INF, INF, 0.0);

    vector offset(q, 0), root(q, 1);

    vector E(q, vector(0, 0));

    stack<pair<int, int>> stk;

    for (int x = 0, z = 0; x < n + 1; ++x)
    {
        while (not empty(stk) && stk.top().second < x)
        {
            auto [w, lprv] = stk.top(); stk.pop();

            if (not empty(stk))
            {
                int u = stk.top().first;
                offset[u] = max(offset[u], offset[w]);
                root[w] = 0;
                E[u].push_back(w);
            }
        }

        for (auto [l, r, p] = V[z]; l == x; tie(l, r, p) = V[++z])
            stk.emplace(z, r);

        if (not empty(stk))
        {
            int w = stk.top().first;
            offset[w] = max(offset[w], a[x]);
        }
    }

    const int N = 5e3 + 1;

    using D = Distribution<N>;

    vector<D> dist(q);

    function<void(int)> compute = [&](int u)
    {
        dist[u].offset = offset[u];

        for (auto v : E[u])
        {
            compute(v);
            dist[u] = dist[u] * dist[v];
        }

        auto [l, r, p] = V[u];

        dist[u] += p;
    };

    D res;

    res.offset = *max_element(all(a));

    for (int u = 0; u < q; ++u) if (root[u])
    {
        compute(u);
        res = res * dist[u];
    }

    double ans = 0.0;

    for (int k = 0; k < N; ++k)
        ans += (res.offset + k) * res.p[k];

    cout << setprecision(20) << fixed;
    cout << ans << endl;

    exit(0);
}