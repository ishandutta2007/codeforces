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

template<typename T>
class SparseTable
{
private:
    const int n;
    const function<T(T, T)>& op;
    vector<int> log;
    vector<vector<T>> st;
public:
    SparseTable(const vector<T>& a, const function<T(T, T)>& op) : n(sz(a)), op(op)
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
    int n; cin >> n;
    vector a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector arr(n, 0); iota(all(arr), 0);
    function<int(int, int)> op = [&a](int i, int j) { return a[i] <= a[j] ? i : j; };
    SparseTable st(arr, op);

    function<int(int, int, int)> solve = [&](int l, int r, int h)
    {
        if (r < l) return 0;
        if (l == r) return a[l] > h ? 1 : 0;
        int m = st.query(l, r);
        return min(r - l + 1, (a[m] - h) + solve(l, m - 1, a[m]) + solve(m + 1, r, a[m]));
    };
    int ans = solve(0, n - 1, 0);
    cout << ans << endl;

    exit(0);
}