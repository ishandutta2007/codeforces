#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template<typename T>
struct F1
{
    int L, R;
    T add;

    F1(T add) : add(add) {}

    void apply_aggregate(T& old) const
    {
        old = old + add * (R - L + 1);
    }
    void compose(const F1<T>& op)
    {
        add += op.add;
    }
    void operator=(const F1& op)
    {
        // this maybe slow if add is a vector
        add = op.add;
    }
};

template<typename T, typename F>
class SegmentTree
{
private:
    const int n, h;
    vector<T> st;
    vector<F> d;
    const T T_id;
    const F F_id;

    T combine(const T& resl, const T& resr)
    {
        return resl + resr;
    }

    void apply(int p)
    {
        d[p].apply_aggregate(st[p]);
        if (p < n)
        {
            d[p << 1].compose(d[p]);
            d[p << 1 | 1].compose(d[p]);
        }
        d[p] = F_id;
    }
    void build(int p)
    {
        while (p > 1)
        {
            p >>= 1;
            // apply(p);
            apply(p << 1);
            apply(p << 1 | 1);
            st[p] = combine(st[p << 1], st[p << 1 | 1]);
        }
    }
    void push(int p)
    {
        for (int s = h; s >= 0; --s)
        {
            int i = p >> s;
            apply(i);
            if (i < n)
            {
                apply(i << 1);
                apply(i << 1 | 1);
            }
        }
    }

public:
    SegmentTree(const vector<T>& a, T T_id, F F_id) :
        n(a.size()),
        h(sizeof(int) * 8 - __builtin_clz(n)),
        T_id(T_id), F_id(F_id)
    {
        st.assign(2 * n, T_id);
        d.assign(2 * n, F_id);

        for (int i = 0; i < n; ++i)
        {
            st[n + i] = a[i];
            d[n + i].L = d[n + i].R = i;
        }

        for (int i = n - 1; i > 0; --i)
        {
            st[i] = combine(st[i << 1], st[i << 1 | 1]);
            d[i].L = d[i << 1].L;
            d[i].R = d[i << 1 | 1].R;
        }
    }
    void update(int l, int r, F op)
    {
        l += n, r += n + 1; // computations are done in [l, r + 1) = [l, r]
        int l0 = l, r0 = r;


        // needs to push for non-commutative operations
        push(l0);
        push(r0 - 1);

        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                d[l].compose(op);
                apply(l++);
            }
            if (r & 1)
            {
                d[r - 1].compose(op);
                apply(--r);
            }
        }
        build(l0);
        build(r0 - 1);
    }
    T query(int l, int r)
    {
        l += n, r += n + 1; // computations are done in [l, r + 1) = [l, r]
        push(l);
        push(r - 1);

        T resl = T_id, resr = T_id;

        for(; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, st[l++]);
            if (r & 1)
                resr = combine(st[--r], resr);
        }
        return combine(resl, resr);
    }
};

ll MOD = 1e9 + 7;

ll power(ll x, int p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = (x * r) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

int main()
{ _
    int n, k; cin >> n >> k;

    vll l(n), r(n), a;
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
        a.pb(l[i]), a.pb(r[i]);
        a.pb(l[i] - 1), a.pb(r[i] - 1);
        a.pb(l[i] + 1), a.pb(r[i] + 1);
    }

    sort(ALL(a));
    a.erase(unique(ALL(a)), a.end());

    map<ll, int> pos;
    for (int z = 0; z < SZ(a); ++z)
        pos[a[z]] = z;

    vll T(SZ(a), 0);
    SegmentTree TREE(T, 0LL, F1<ll>(0LL));

    for (int i = 0; i < n; ++i)
        TREE.update(pos[l[i]], pos[r[i]], F1<ll>(1LL));

    vll f(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        f[i] = i * f[i - 1] % MOD, inv[i] = power(f[i], MOD - 2);

    auto bin = [&f, &inv](int n, int k) -> ll
    {
        return (f[n] * inv[k] % MOD) * inv[n - k] % MOD;
    };

    ll ans = 0;

    for (int z = 0; z < SZ(a); ++z)
    {
        int L = TREE.query(z, z);

        if (L < k)
            continue;

        int v = z;
        while (v + 1 < SZ(a) && TREE.query(v + 1, v + 1) == L)
            v += 1;

        ans = (ans + (a[v] - a[z] + 1) * bin(L, k)) % MOD;
        z = v;
    }

    cout << ans << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/