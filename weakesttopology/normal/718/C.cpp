#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll mod = 1e9 + 7;

#define W 70

struct Matrix
{
    ll X[2][2];

    Matrix(ll a = 1, ll b = 0, ll c = 0, ll d = 1)
    {
        X[0][0] = a;
        X[0][1] = b;
        X[1][0] = c;
        X[1][1] = d;
    }

    Matrix operator*(const Matrix& R) const
    {
        Matrix Z(0, 0, 0, 0);

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    Z.X[i][j] = (Z.X[i][j] + X[i][k] * R.X[k][j]) % mod;

        return Z;
    }

    pll operator*(const pll& y) const
    {
        ll a = (X[0][0] * y.f + X[0][1] * y.s) % mod;
        ll b = (X[1][0] * y.f + X[1][1] * y.s) % mod;

        return {a, b};
    }
};

Matrix Q[W];

Matrix A(ll p)
{
    Matrix R;

    ll i = 0;
    while (p)
    {
        if (p & 1)
            R = Q[i] * R;
        p >>= 1;
        i++;
    }

    return R;
}

template<typename T>
struct F1
{
    int L, R;
    Matrix add;

    F1(Matrix add) : add(add) {}

    void apply_aggregate(T& old) const
    {
        old = add * old;
    }
    void compose(const F1<T>& op)
    {
        add = add * op.add;
    }
    void operator=(const F1& op)
    {
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

    T combine(const T& left, const T& right)
    {
        return {(left.f + right.f) % mod, (left.s + right.s) % mod};
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
        // push(l0);
        // push(r0 - 1);

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

int main()
{ _
    Q[0] = Matrix(0, 1, 1, 1);
    for (int i = 1; i < W; ++i)
        Q[i] = Q[i - 1] * Q[i - 1];

    int n, m; cin >> n >> m;
    vector<pll> a(n);

    for (int i = 0; i < n; ++i)
    {
        int p; cin >> p;
        a[i] = A(p) * make_pair(0, 1);
    }
    SegmentTree<pll, F1<pll>> T(a, {0, 0}, F1<pll>(A(0)));

    for (int i = 0; i < m; ++i)
    {
        int t; cin >> t;
        int l, r; cin >> l >> r; --l; --r;
        if (t == 2)
            cout << T.query(l, r).f << endl;
        else
        {
            int x = 0; cin >> x;
            T.update(l, r, F1<pll>(A(x)));
        }
    }

    exit(0);
}