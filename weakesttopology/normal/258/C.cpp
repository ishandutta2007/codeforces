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

const ll MOD = 1e9 + 7;

ll power(ll x, int p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = (r * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }
    return r;
}

int main()
{ _
    const int N = 1e6;
    int lp[N + 1] = { 0 };
    vi pr;

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
            lp[i] = i, pr.pb(i);

        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N)
                break;
            lp[i * p] = p;
        }
    }

    int n; cin >> n;
    vi a(n); READ(a);

    vi C(N + 1, 0);
    for (int i = 0; i < n; ++i)
        ++C[a[i]];

    for (int i = 1; i <= N; ++i)
        C[i] += C[i - 1];

    ll ans = 1;

    int M = *max_element(ALL(a));
    for (int m = 2; m <= M; ++m)
    {
        vi f;
        for (int p = m; p > 1; p /= lp[p])
            f.pb(lp[p]);

        set<int> DIV; DIV.insert(1);
        for (auto p : f)
        {
            vi temp;
            for (auto x : DIV)
                temp.pb(x * p);
            DIV.insert(ALL(temp));
        }

        vi div;
        for (auto d : DIV)
            div.pb(d);

        ll cur = 1;

        for (int i = 0; i + 1 < SZ(div); ++i)
        {
            int z = (n - C[div[i] - 1]) - (n - C[div[i + 1] - 1]);
            cur = (cur * power(i + 1, z)) % MOD;
        }

        cur = (cur * (power(SZ(div), n - C[m - 1]) - power(SZ(div) - 1, n - C[m - 1])) % MOD) % MOD;
        ans = (ans + cur) % MOD;
    }

    ans = (ans + MOD) % MOD;
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