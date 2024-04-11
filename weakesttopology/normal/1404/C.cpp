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
struct SegmentTree
{
private:
    const int n; const T Tid;
    vector<T> st;
    T combine(T l, T r) { return l + r; }
public:
    SegmentTree(const int n, T Tid) : n(n), Tid(Tid) { st.assign(2 * n, Tid); }
    T query(int p)
    {
        T res = Tid;
        for (p += n; p; p >>= 1)
            res = combine(res, st[p]);
        return res;
    }
    void update(int l, int r, T value) // inclusive
    {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) st[l] = combine(st[l], value), ++l;
            if (r & 1) --r, st[r] = combine(st[r], value);
        }
    }
};

int main()
{ _
    int n, q; cin >> n >> q;

    vector a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] = i + 1 - a[i];
    }

    vector x(q, 0), y(q, 0);
    for (int j = 0; j < q; ++j)
    {
        cin >> x[j] >> y[j];
        y[j] = n - 1 - y[j];
    }
    vector I(q, 0); iota(all(I), 0);
    sort(all(I), [&y](int i, int j) { return y[i] < y[j]; });

    SegmentTree st(n, 0);

    auto find = [&st](int a, int r)
    {
        int l = -1;
        for (int z = r + 1; z; z >>= 1)
            while (l + z <= r && st.query(l + z) >= a) l += z;
        return l;
    };

    vector ans(q, 0);

    int z = 0;
    for (int i = 0; i < n && z < q; ++i)
    {
        if (a[i] >= 0)
        {
            int j = find(a[i], i);
            if (j != -1) st.update(0, j, 1);
        }

        while (z < q && y[I[z]] == i)
            ans[I[z]] = st.query(x[I[z]]), ++z;
    }

    for (int j = 0; j < q; ++j) cout << ans[j] << endl;

    exit(0);
}