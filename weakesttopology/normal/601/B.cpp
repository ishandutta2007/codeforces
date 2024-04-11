#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
class SparseTable
{
private:
    const int n;
    const function<T(T, T)> op;
    vector<int> log;
    vector<vector<T>> st;
public:
    SparseTable(const vector<T>& a, const function<T(T, T)> op) : n(sz(a)), op(op)
    {
        log.assign(n + 1, 0);
        for (int x = 1; x <= n; ++x) log[x] = 31 - __builtin_clz(x);
        st.assign(n, vector<T>(log[n] + 1, T()));
        for (int i = 0; i < n; ++i) st[i][0] = a[i];
        for (int x = 1; x <= log[n]; ++x)
            for (int i = 0; i + (1 << x) <= n; ++i)
                st[i][x] = op(st[i][x - 1], st[i + (1 << (x - 1))][x - 1]);
    }
    T query(int l, int r)
    {
        int x = log[r - l + 1];
        return op(st[l][x], st[r - (1 << x) + 1][x]);
    }
};

int main()
{ _
    int n, q; cin >> n >> q;

    vector a(n, 0);
    for (auto& x : a) cin >> x;

    vector D(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) D[i] = abs(a[i + 1] - a[i]);

    vector I(n - 1, 0); iota(all(I), 0);
    SparseTable<int> st(I, [&](int i, int j){ return D[i] >= D[j] ? i : j; });

    function<ll(int, int)> solve = [&](int l, int r)
    {
        if (r - l < 1) return 0LL;

        int m = st.query(l, r - 1);

        ll ct = ll(m - l + 1) * ll(r - (m + 1) + 1);

        return ct * D[m] + solve(l, m) + solve(m + 1, r);
    };

    while (q--)
    {
        int l, r; cin >> l >> r; --l, --r;
        ll ans = solve(l, r);
        cout << ans << endl;
    }

    exit(0);
}