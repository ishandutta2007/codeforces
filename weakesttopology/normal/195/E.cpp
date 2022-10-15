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

const ll MOD = 1e9 + 7;

class UFDS
{
private:
    vector<int> p, rk, sz;
    int num_disjoint_sets;
public:
    UFDS(int n)
    {
        rk.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        num_disjoint_sets = n;
        sz.assign(n, 1);
    }
    int find_set(int i)
    {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }
    bool is_same_set(int i, int j)
    {
        return find_set(i) == find_set(j);
    }
    void union_set(int i, int j)
    {
        int x = find_set(i), y = find_set(j);
        if (x != y)
        {
            --num_disjoint_sets;
            if (rk[x] >= rk[y])
            {
                p[y] = x;
                rk[x] += (rk[x] == rk[y]);
                sz[x] += sz[y];
            }
            else
            {
                p[x] = y;
                sz[y] += sz[x];
            }
        }
    }
    int set_size(int i)
    {
        return sz[find_set(i)];
    }
    int num_sets()
    {
        return num_disjoint_sets;
    }
};

template<typename T>
struct F1
{
    int L, R;
    T add;

    F1(T add) : add(add) {}

    void apply_aggregate(T& old) const
    {
        old = (old + add * (R - L + 1)) % MOD;
    }
    void compose(const F1<T>& op)
    {
        add = (add + op.add) % MOD;
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
        return (resl + resr) % MOD;
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

int ct = 0;
vi L, R;
void dfs(const vvi& E, int u)
{
    L[u] = ct++;
    for (auto v : E[u])
        dfs(E, v);
    R[u] = ct;
}

int main()
{ _
    int n; cin >> n;

    ll ans = 0;

    vvi E(n), F(n); vi d(n, 0);
    vi root(n, 0); UFDS S(n); vll X(n, 0);
    for (int u = 0; u < n; ++u)
    {
        int k; cin >> k;
        for (int l = 0; l < k; ++l)
        {
            int v, x; cin >> v >> x; --v;
            int r = root[S.find_set(v)];
            E[u].pb(v); F[u].pb(r);
            X[r] = x; d[r]++;
            S.union_set(u, v);
            ans = (ans + x) % MOD;
        }
        root[S.find_set(u)] = u;
    }

    L.assign(n, -1), R.assign(n, -1);
    for (int u = 0; u < n; ++u)
        if (not d[u])
            dfs(F, u);

    vll a(n, 0);
    SegmentTree<ll, F1<ll>> TREE(a, 0, F1<ll>(0));

    root.assign(n, 0); S = UFDS(n);
    for (int u = 0; u < n; ++u)
    {
        for (int l = 0; l < SZ(E[u]); ++l)
        {
            int v = E[u][l], r = root[S.find_set(v)];
            ll depth = TREE.query(L[v], L[v]);
            ans = (ans + depth) % MOD;
            TREE.update(L[r], R[r] - 1, depth + X[r]);
            S.union_set(u, v);
        }
        root[S.find_set(u)] = u;
    }

    ans = (ans + MOD) % MOD;
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