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
    T query(int p)
    {
        T res = id;
        for (int i = p; i >= 0; i = down(i))
            res = combine(ft[i], res);
        return res;
    }
public:
    BIT(const int n, T id) : n(n), id(id) { ft.assign(n, id); }
    T query(int l, int r)
    {
        if (l == 0) return query(r);
        return combine(inv(query(l - 1)), query(r));
    }
    void update(int p, T value)
    {
        for (int i = p; i < n; i = up(i)) ft[i] = combine(ft[i], value);
    }
};

int main()
{ _
    const int N = 1e5 + 1;

    int n, m; cin >> n >> m;

    vector c(n, 0);
    for (int i = 0; i < n; ++i) cin >> c[i];

    vector E(n, vector(0, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector Q(n, vector(0, 0));
    vector k(m, 0);
    vector ans(m, 0);

    for (int j = 0; j < m; ++j)
    {
        int v; cin >> v >> k[j]; --v;
        Q[v].push_back(j);
    }

    vector L(n, 0), R(n, 0), vtx(n, 0), heavy(n, -1);
    function<int(int, int)> flatten = [&](int u, int p)
    {
        static int ct = 0;
        int size = 1, mx = 0;
        L[u] = ct;
        for (auto v : E[u])
            if (v != p)
            {
                int y = flatten(v, u);
                if (y > mx) heavy[u] = v, mx = y;
                size += y;
            }
        vtx[ct] = u;
        R[u] = ct++;
        return size;
    };
    flatten(0, 0);

    BIT bit(N, 0); bit.update(0, n);
    vector ct(N, 0);

    auto update = [&](int v, int add)
    {
        for (int i = L[v]; i <= R[v]; ++i)
        {
            bit.update(ct[c[vtx[i]]], -1);
            ct[c[vtx[i]]] += add;
            bit.update(ct[c[vtx[i]]], +1);
        }
    };

    function<void(int, int, bool)> compute = [&](int u, int p, bool keep)
    {
        for (auto v : E[u])
            if (v != p && v != heavy[u])
                compute(v, u, false);

        if (heavy[u] != -1) compute(heavy[u], u, true);

        for (auto v : E[u])
            if (v != p && v != heavy[u]) update(v, 1);

        bit.update(ct[c[u]], -1);
        ct[c[u]]++;
        bit.update(ct[c[u]], 1);

        // answer queries...
        for (auto j : Q[u])
            ans[j] = (k[j] <= n) ? bit.query(k[j], n) : 0;

        if (not keep) update(u, -1);
    };
    compute(0, 0, true);

    for (auto ct : ans) cout << ct << endl;

    exit(0);
}