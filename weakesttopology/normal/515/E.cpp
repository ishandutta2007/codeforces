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

// K >= floor(log(n))

template<typename T, int K>
class SparseTable
{
private:
    const int n;
    const function<T(T, T)> op;
    vector<array<T, K + 1>> st;
    vector<int> log;
public:
    SparseTable(const vector<T>& a, auto op) : n(size(a)), op(op), st(n), log(n + 1)
    {
        for (int x = 1; x <= n; ++x) log[x] = __builtin_clz(1) - __builtin_clz(x);
        assert(log[n] <= K);
        for (int i = 0; i < n; ++i) st[i][0] = a[i];
        for (int x = 1; x <= log[n]; ++x)
            for (int i = 0; i + (1 << x) <= n; ++i)
                st[i][x] = op(st[i][x - 1], st[i + (1 << (x - 1))][x - 1]);
    }
    SparseTable(const vector<T>& a) : SparseTable(a, [](T x, T y){ return min(x, y); }) { }
    T query(int l, int r) const
    {
        assert(l <= r);
        int x = log[r - l + 1];
        return op(st[l][x], st[r - (1 << x) + 1][x]);
    }
};

int main()
{ _
    int n, q; cin >> n >> q;

    vector<int> d(n);
    for (auto& x : d) cin >> x;

    vector<int> h(n);
    for (auto& x : h) cin >> x;

    vector<ll> L(2 * n, 0), R(2 * n, 0);

    for (int x = 1; x < 2 * n; ++x)
    {
        L[x] = -d[(x - 1) % n] + L[x - 1];
        R[x] = +d[(x - 1) % n] + R[x - 1];
    }

    for (int x = 0; x < 2 * n; ++x)
    {
        L[x] += 2 * h[x % n];
        R[x] += 2 * h[x % n];
    }

    ll* ptr = nullptr;

    auto cmp = [&ptr](int i, int j) { return ptr[i] > ptr[j]; };
    auto op = [&cmp](auto p, auto q)
    {
        auto [pi, pj] = p;
        auto [qi, qj] = q;

        int arr[4] = { pi, pj, qi, qj };
        sort(all(arr), cmp), unique(all(arr));

        return pair<int, int>(arr[0], arr[1]);
    };

    using RMQ = SparseTable<pair<int, int>, 17>;

    vector<pair<int, int>> Idx(2 * n);
    for (int x = 0; x < 2 * n; ++x) Idx[x] = { x, x };

    ptr = &L[0];
    RMQ stL(Idx, op); 
    ptr = &R[0];
    RMQ stR(Idx, op); 

    for (int z = 0; z < q; ++z)
    {
        int a, b; cin >> a >> b; --a, --b;

        if (a <= b)
        {
            tie(a, b) = pair(b + 1, a + n - 1);
        }
        else
        {
            tie(a, b) = pair(b + 1, a - 1);
        }

        ptr = &L[0];
        auto [Li, Lj] = stL.query(a, b);
        ptr = &R[0];
        auto [Ri, Rj] = stR.query(a, b);

        ll ans = 0LL;

        int I[2] = { Li, Lj }, J[2] = { Ri, Rj };

        for (auto i : I) for (auto j : J)
        {
            if (i != j)
            {
                ans = max(ans, L[i] + R[j]);
            }
        }

        cout << ans << endl;
    }

    exit(0);
}