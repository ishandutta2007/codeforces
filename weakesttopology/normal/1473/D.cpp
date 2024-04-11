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

void solve()
{
    int n, m; cin >> n >> m;

    vector<int> a(n);

    for (auto& x : a)
    {
        char ch; cin >> ch;
        x = ch == '+' ? +1 : -1;
    }

    for (int i = 1; i < n; ++i) a[i] += a[i - 1];

    vector<pair<int, int>> init(n);
    for (int i = 0; i < n; ++i) init[i] = { a[i], a[i] };

    auto op = [&](pair<int, int> p, pair<int, int> q)
    {
        auto [px, py] = p;
        auto [qx, qy] = q;
        return pair<int, int>(min(px, qx), max(py, qy));
    };
    SparseTable<pair<int, int>, 18> st(init, op);

    for (int j = 0; j < m; ++j)
    {
        int l, r; cin >> l >> r; --l, --r;

        pair<int, int> rng(0, 0);

        if (l > 0) rng = op(rng, st.query(0, l - 1));

        if (r + 1 < n)
        {
            auto p = st.query(r + 1, n - 1);
            int add = l > 0 ? a[l - 1] : 0;
            p.first += add - a[r], p.second += add - a[r];
            rng = op(rng, p);
        }

        int ans = rng.second - rng.first + 1;

        cout << ans << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}