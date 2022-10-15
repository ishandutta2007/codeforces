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

vi arr(1e6);
SegmentTree TREE(arr, 0, F1(0));

vi parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, const vvi& E)
{
    int size = 1;
    int max_c_size = 0;
    for (int c : E[v])
        if (c != parent[v])
        {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, E);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }

    return size;
}

void decompose(int v, int h, const vvi& E)
{
    head[v] = h, pos[v] = cur_pos++;

    if (heavy[v] != -1)
        decompose(heavy[v], h, E);

    for (int c : E[v])
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, E);
}

void init(const vvi& E)
{
    int n = E.size();

    parent = vi(n);
    depth = vi(n);
    heavy = vi(n, -1);
    head = vi(n);
    pos = vi(n);
    cur_pos = 0;

    dfs(0, E);
    decompose(0, 0, E);
}

void update(int a, int b, int value = 0)
{
    for (; head[a] != head[b]; b = parent[head[b]])
    {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);

        TREE.update(pos[head[b]], pos[b], 1);
    }

    if (depth[a] > depth[b])
        swap(a, b);

    TREE.update(pos[a], pos[b], 1);
}

int main()
{ _
    int n; cin >> n;

    vvi E(2 * n - 1);

    for (int i = 0; i + 1 < n; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].pb(n + i);
        E[n + i].pb(u);
        E[v].pb(n + i);
        E[n + i].pb(v);
    }
    init(E);

    int k; cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int a, b; cin >> a >> b; --a, --b;
        update(a, b, 1);
    }

    for (int i = 0; i + 1 < n; ++i)
        cout << TREE.query(pos[n + i], pos[n + i]) << " ";
    cout << endl;

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