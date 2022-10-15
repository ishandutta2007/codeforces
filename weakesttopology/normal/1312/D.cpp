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

const ll MOD = 998244353LL;

ll power(ll x, ll p)
{
    ll r = 1;

    while (p)
    {
        if (p & 1)
            r = (r * x) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }

    return r;
}

int main()
{ _
    ll n, m; cin >> n >> m;

    if (n == 2)
    {
        cout << 0 << endl;
        exit(0);
    }

    vll f(m + 1, 1), inv(m + 1, 1);
    for (int i = 2; i <= m; ++i)
    {
        f[i] = (i * f[i - 1]) % MOD;
        inv[i] = power(f[i], MOD - 2);
    }

    ll b = (f[m] * inv[n - 1] % MOD) * inv[m - (n - 1)] % MOD;

    ll ans = (b * (n - 2) % MOD) * power(2, n - 3) % MOD;

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