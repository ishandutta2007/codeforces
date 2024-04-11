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
    int n, h; cin >> n >> h;

    vi a(n); READ(a);

    if (*max_element(ALL(a)) > h)
    {
        cout << 0 << endl;
        exit(0);
    }

    vvll dp(n, vll(h + 1, 0));

    if (a[0] == h - 1)
    {
        dp[0][1] = 1;
        dp[0][0] = 1;
    }
    else if (a[0] == h)
        dp[0][0] = 1;

    ll MOD = 1e9 + 7;

    for (int i = 1; i < n; ++i)
    {
        int d = h - a[i];

        dp[i][d] = dp[i - 1][d];
        if (d)
        {
            dp[i][d] = (dp[i][d] + dp[i - 1][d - 1]) % MOD;
            dp[i][d - 1] = (d * dp[i - 1][d] + d * dp[i - 1][d - 1]) % MOD;
        }
    }

    ll ans = (dp[n - 1][0] + MOD) % MOD;

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