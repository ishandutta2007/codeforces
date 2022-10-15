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

vi primes(int n)
{
    vi p;
    if (n % 2 == 0)
    {
        p.pb(2);
        while (n % 2 == 0)
            n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            p.pb(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        p.pb(n);

    return p;
}

int main()
{ _
    int n; cin >> n;
    vi l(n), c(n); READ(l); READ(c);

    int ans = INF;

    for (int i = 0; i < n; ++i)
    {
        vi p = primes(l[i]);
        vi dp(1 << SZ(p), INF); dp[0] = 0;

        vi inter(n, 0);
        for (int z = 0; z < SZ(p); ++z)
            for (int j = 0; j < n; ++j)
                if (l[j] % p[z])
                    inter[j] |= 1 << z;

        for (int mask = 1; mask < (1 << SZ(p)); ++mask)
            for (int j = 0; j < n; ++j)
                dp[mask] = min(dp[mask], c[j] + dp[mask & ~inter[j]]);

        ans = min(ans, c[i] + dp.back());
    }

    if (ans == INF)
        ans = -1;

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