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
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i]
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

ll mod = 1e9 + 7;

ll f[2001], inv[2001];

ll mod_pow(ll x, int k)
{
    ll p = 1;
    x %= mod;

    while (k)
    {
        if (k & 1)
            p = (p * x) % mod;

        k >>= 1;
        x = (x * x) % mod;
    }

    return p;
}

ll comb(int n, int r)
{
    return ((f[n - 1 + r] * inv[n - 1]) % mod) * inv[r] % mod;
}

int main()
{ _
    f[0] = 1; f[1] = 1;
    inv[0] = 1; inv[1] = 1;

    for (ll i = 2; i <= 2000; ++i)
    {
        f[i] = (i * f[i - 1]) % mod;
        inv[i] = mod_pow(f[i], mod - 2);
    }

    int n, m; cin >> n >> m;

    ll ans = 0;

    for (int k = 1; k <= n; ++k)
        ans = (ans + comb(k, m - 1) * comb(n - k + 1, m) % mod) % mod;

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