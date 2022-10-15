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
    int n; cin >> n;

    map<int, int> F;
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        ++F[a];
    }

    vll keys;
    for (auto [k, v] : F)
        keys.pb(k);

    int K = SZ(keys);

    if (K == 1)
    {
        ll ans = F[keys[0]] * keys[0];
        cout << ans << endl;
        exit(0);
    }

    vll dp(K, 0);
    dp[0] = F[keys[0]] * keys[0];
    dp[1] = F[keys[1]] * keys[1];

    if (keys[0] + 1 != keys[1])
        dp[1] += dp[0];

    vll ans (K, 0);
    ans[0] = dp[0];
    ans[1] = max(dp[0], dp[1]);

    for (int i = 2; i < K; ++i)
    {
        dp[i] = F[keys[i]] * keys[i] + (keys[i - 1] + 1 == keys[i] ? ans[i - 2] : max(dp[i - 1], dp[i - 2]));
        ans[i] = max(ans[i - 1], dp[i]);
    }

    cout << ans.back() << endl;

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