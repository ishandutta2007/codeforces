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

int main()
{ _
    int n, k, d; cin >> n >> k >> d;

    ll MOD = 1e9 + 7;

    vll dp(n + 1, 0), dpsum(n + 1, 0); dp[0] = dpsum[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dpsum[i - 1];
        if (i - k > 0)
            dp[i] = (dp[i] - dpsum[i - k - 1]) % MOD;
        dpsum[i] = (dpsum[i - 1] + dp[i]) % MOD;
    }

    vll dpd(n + 1, 0), dpdsum(n + 1, 0); dpd[0] = dpdsum[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        int l = min(k, d - 1);

        dpd[i] = dpdsum[i - 1];
        if (i - l > 0)
            dpd[i] = (dpd[i] - dpdsum[i - l - 1]) % MOD;
        dpdsum[i] = (dpdsum[i - 1] + dpd[i]) % MOD;
    }

    ll ans = ((dp[n] - dpd[n]) % MOD + MOD) % MOD;

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