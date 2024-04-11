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

ll MOD = 1e9 + 7;

bool contained(ii ul, ii md, ii lr)
{
    bool x = ul.f <= md.f && md.f <= lr.f;
    bool y = ul.s <= md.s && md.s <= lr.s;
    return x && y;
}

ll power(ll x, int p)
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
    int h, w, n; cin >> h >> w >> n;

    vi r(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> r[i] >> c[i];

    vi I(n);
    for (int i = 0; i < n; ++i)
        I[i] = i;
    sort(ALL(I), [&r, &c](int i, int j){ return mp(r[i], c[i]) < mp(r[j], c[j]); });

    int N = 2* max(h, w) + 1;
    vll f(N, 1), inv(N, 1);
    for (int z = 2; z < N; ++z)
    {
        f[z] = (z * f[z - 1]) % MOD;
        inv[z] = power(f[z], MOD - 2);
    }

    auto ways = [&f, &inv](int x, int y){ return (f[x + y] * inv[x] % MOD) * inv[y] % MOD; };

    ll ans = 0;
    vll dp(n, 0);

    for (auto i : I)
    {
        dp[i] = ways(r[i] - 1, c[i] - 1);
        for (auto j : I)
        {
            if (j == i)
                break;
            if (contained(mp(1, 1), mp(r[j], c[j]), mp(r[i], c[i])))
            {
                ll v = dp[j] * ways(r[i] - r[j], c[i] - c[j]);
                dp[i] = (dp[i] - v) % MOD;
            }
        }

        ans = (ans + dp[i] * ways(h - r[i], w - c[i])) % MOD;
    }

    ans = ((ways(h - 1, w - 1) - ans) % MOD + MOD) % MOD;

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