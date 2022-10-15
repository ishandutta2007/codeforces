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

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        ll n, m; cin >> n >> m;
        vll a(m), b(m);
        for (int j = 0; j < m; ++j)
            cin >> a[j] >> b[j];

        vll x = a; sort(x.rbegin(), x.rend());
        vll sum(m, 0); sum[0] = x[0];
        for (int j = 1; j < m; ++j)
            sum[j] = x[j] + sum[j - 1];

        ll ans = 0;

        for (int j = 0; j < m; ++j)
        {
            ll cur = 0, w = n;
            int e = -1;
            for (int z = w; z; z >>= 1)
                while (e + z < min(w, m) && x[e + z] >= b[j])
                    e += z;
            if (e != -1)
                w -= e + 1, cur += sum[e];

            if (a[j] < b[j])
            {
                cur += a[j], w -= 1;
                if (w < 0)
                    w += 1, cur -= x[e];
            }

            cur += w * b[j];
            ans = max(cur, ans);
        }

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