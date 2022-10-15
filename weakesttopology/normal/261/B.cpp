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
    int n; cin >> n;
    vi a(n); READ(a);
    int p; cin >> p;

    if (accumulate(ALL(a), 0) <= p)
    {
        cout << n << endl;
        exit(0);
    }

    int M = *max_element(ALL(a));
    vector sum(n, vvll(n + 1, vll(n * M + 1, 0)));

    for (int i = 0; i < n; ++i)
        sum[i][0][0] = 1;

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i == j)
                continue;
            for (int s = n - 1; s >= 0 ; --s)
                for (int x = 0; x < n * M; ++x)
                    sum[j][s + 1][x + a[i]] += sum[j][s][x];
        }
    }

    for (int j = 0; j < n; ++j)
        for (int s = 1; s < n; ++s)
            for (int x = p - 1; x >= 0; --x)
                sum[j][s][x] += sum[j][s][x + 1];

    vector<double> f(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        f[i] = i * f[i - 1];

    double ans = 0;

    for (int i = 0; i < n; ++i)
        for (int s = 1; s < n; ++s)
            ans += s * (f[s] * f[n - s - 1] * sum[i][s][max(1, p - a[i] + 1)]) / f[n];

    cout << setprecision(10) << fixed;
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