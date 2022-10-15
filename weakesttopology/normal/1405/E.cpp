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
class BIT
{
private:
    inline T combine(T x, T y) { return x + y; }
    inline T inv(T x) { return -x; }

    inline int down(int p) { return (p & (p + 1)) - 1; }
    inline int up(int p) { return p | (p + 1); }

    const int n; const T id;
    vector<T> ft;
    void update(int p, T value)
    {
        for (int i = p; i >= 0; i = down(i))
            ft[i] = combine(ft[i], value);
    }
public:
    BIT(const int n, T id) : n(n), id(id) { ft.assign(n, id); }
    void update(int l, int r, T value)
    {
        if (l) update(l - 1, inv(value));
        update(r, value);
    }
    T query(int p)
    {
        T res = id;
        for (int i = p; i < n; i = up(i)) res = combine(res, ft[i]);
        return res;
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

    BIT bit(n, 0);

    auto find = [&bit](int a, int r)
    {
        int l = -1;
        for (int z = r + 1; z; z >>= 1)
            while (l + z <= r && bit.query(l + z) >= a) l += z;
        return l;
    };

    vector ans(q, 0);

    int z = 0;
    for (int i = 0; i < n && z < q; ++i)
    {
        if (a[i] >= 0)
        {
            int j = find(a[i], i);
            if (j != -1) bit.update(0, j, 1);
        }

        while (z < q && y[I[z]] == i)
            ans[I[z]] = bit.query(x[I[z]]), ++z;
    }

    for (int j = 0; j < q; ++j) cout << ans[j] << endl;

    exit(0);
}