#include "bits/stdc++.h"

using namespace std;

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
        old = max(old, add);
    }
    void compose(const F1<T>& op)
    {
        add = max(add, op.add);
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
        return max(resl, resr);
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

struct Query
{
    int x, y;
    char c;
};

int main()
{ _
    int n, q; cin >> n >> q;

    vector<Query> Q(q);

    vi L, U;

    for (int z = 0; z < q; ++z)
    {
        cin >> Q[z].x >> Q[z].y >> Q[z].c;
        if (Q[z].c == 'L')
            L.pb(z);
        else
            U.pb(z);
    }

    if (L.empty() || U.empty())
    {
        set<int> X;
        for (int z = 0; z < q; ++z)
        {
            if (X.count(Q[z].x) == 0)
            {
                int ans = Q[z].c == 'L' ? Q[z].x : Q[z].y;
                cout << ans << endl;
                X.insert(Q[z].x);
            }
            else
                cout << 0 << endl;
        }
        exit(0);
    }

    sort(ALL(L), [&Q](int i, int j){ return Q[i].y < Q[j].y; });
    sort(ALL(U), [&Q](int i, int j){ return Q[i].x < Q[j].x; });

    vi pos(q, 0);
    for (int i = 0; i < SZ(L); ++i)
        pos[L[i]] = i;
    for (int i = 0; i < SZ(U); ++i)
        pos[U[i]] = i;

    vi _L(SZ(L), 0), _U(SZ(U), 0);
    SegmentTree LTREE(_L, 0, F1(0)), UTREE(_U, 0, F1(0));

    set<ii> C;

    for (int z = 0; z < q; ++z)
    {
        int ans = 0;

        if (C.count(mp(Q[z].x, Q[z].y)))
        {
            cout << 0 << endl;
            continue;
        }

        if (Q[z].c == 'L')
        {
            int h = LTREE.query(pos[z], pos[z]);

            ans = Q[z].x - h;

            int l = 0;
            for (int b = SZ(U) - l; b; b >>= 1)
                while (l + b < SZ(U) && Q[U[l + b]].x <= h)
                    l += b;

            int r = -1;
            for (int b = SZ(U) - r; b; b >>= 1)
                while (r + b < SZ(U) && Q[U[r + b]].x <= Q[z].x)
                    r += b;

            if (l <= r)
                UTREE.update(l, r, Q[z].y);
        }
        else
        {
            int h = UTREE.query(pos[z], pos[z]);

            ans = Q[z].y - h;

            int l = 0;
            for (int b = SZ(L) - l; b; b >>= 1)
                while (l + b < SZ(L) && Q[L[l + b]].y <= h)
                    l += b;

            int r = -1;
            for (int b = SZ(L) - r; b; b >>= 1)
                while (r + b < SZ(L) && Q[L[r + b]].y <= Q[z].y)
                    r += b;

            if (l <= r)
                LTREE.update(l, r, Q[z].x);
        }

        C.insert(mp(Q[z].x, Q[z].y));

        cout << ans << endl;
    }

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