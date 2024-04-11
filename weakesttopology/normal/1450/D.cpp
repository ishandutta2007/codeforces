#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
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

string solve()
{
    int n; cin >> n;

    vector a(n, 0);

    for (auto& x : a) { cin >> x; --x; }

    SparseTable<int, 19> st(a);

    vector lengths(n, vector(0, 0));

    for (int i = 0; i < n; ++i)
    {
        int l = i, r = i;

        for (int z = i; z > 0; z >>= 1)
            while (l - z >= 0 && st.query(l - z, i) == a[i]) l -= z;

        for (int z = n - i; z > 0; z >>= 1)
            while (r + z < n && st.query(i, r + z) == a[i]) r += z;

        lengths[a[i]].push_back(r - l + 1);
    }

    vector maxgood(n, 0);

    for (int x = 0; x < n; ++x)
    {
        if (empty(lengths[x]))
            maxgood[x] = -1;
        else
            maxgood[x] = *max_element(all(lengths[x]));
    }

    for (int x = 1; x < n; ++x)
        maxgood[x] = min(maxgood[x - 1], maxgood[x]);

    string ans(n, '0');

    for (int x = 0; x < n; ++x)
        if (maxgood[x] >= n - x) ans[x] = '1';

    reverse(all(ans));

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}