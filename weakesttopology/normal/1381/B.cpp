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

vii reduce(const vii& p)
{
    int n = SZ(p);

    vi sizes, start; start.pb(p[0].f);
    for (int i = 1, s = p[0].s; i < n; ++i)
    {
        if (p[i] < p[i - 1])
            s += p[i].s;
        else
        {
            sizes.pb(s);
            start.pb(p[i].f);
            s = p[i].s;
        }

        if (i == n - 1)
            sizes.pb(s);
    }

    vii q;
    for (int i = 0; i < SZ(sizes); ++i)
        q.pb(mp(start[i], sizes[i]));
    return q;
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vii p(2 * n);
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> p[i].f;
            p[i].s = 1;
        }

        while (not is_sorted(ALL(p)))
            p = reduce(p);

        vvi sums(2, vi(2 * n + 1, 0)); sums[0][0] = 1;
        int b = 0;

        for (auto [x, sz] : p)
        {
            sums[!b].assign(2 * n + 1, 0);

            for (int m = 0; m < 2 * n; ++m)
                if (sums[b][m])
                    sums[!b][m + sz] = 1;

            for (int m = 0; m <= 2 * n; ++m)
                sums[!b][m] = sums[b][m] || sums[!b][m];

            b = !b;
        }

        if (sums[b][n])
            cout << "YES\n";
        else
            cout << "NO\n";

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