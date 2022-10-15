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

struct SegmentTree
{
    int n;
    vector<double> st;

    const double default_value = 0;
    double op(double l, double r)
    {
        return l + r;
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            st[i] = op(st[i << 1], st[i << 1 | 1]);
    }

    void modify(int p, double value)
    {
        for (st[p += n] += value; p > 1; p >>= 1)
            st[p >> 1] = op(st[p], st[p ^ 1]);
    }

    // inclusive
    double query(int l, int r)
    {
        double res = default_value;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = op(st[l++], res);
            if (r & 1)
                res = op(res, st[--r]);
        }
        return res;
    }
};

int main()
{ _
    int n, m; cin >> n >> m;
    vi x(n); READ(x);

    ll S = accumulate(ALL(x), 0LL);

    if (S == n)
    {
        cout << 1 << endl;
        exit(0);
    }

    int N = n * m;
    vector TREE(2, SegmentTree());

    for (int i = 0; i < 2; ++i)
    {
        TREE[i].n = N + 1;
        TREE[i].st.assign(2 * (N + 1), 0.0);
        TREE[i].build();
    }
    TREE[0].modify(0, 1);

    for (int i = 0; i < n; ++i)
    {
        int b = i % 2;

        TREE[!b].st.assign(2 * (N + 1), 0.0);
        TREE[!b].build();

        for (int k = 1; k <= S; ++k)
        {
            TREE[!b].modify(k, TREE[b].query(max(0, k - m), k - 1));
            if (k - x[i] >= 0)
                TREE[!b].modify(k, -TREE[b].query(k - x[i], k - x[i]));
        }
    }

    auto ans = 1.0L + (m - 1) * (TREE[n % 2].query(0, S - 1) / pow((double)(m - 1), n));

    cout << setprecision(16) << fixed;
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