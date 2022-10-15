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
    vll a(n); READ(a);

    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    if (sum % 3)
    {
        cout << 0 << endl;
        exit(0);
    }

    ll csum = 0;

    vi b;
    for (int i = 0; i + 1 < n; ++i)
    {
        csum += a[i];
        if (csum == 2 * sum / 3)
            b.pb(i + 1);
    }

    ll ans = 0;

    csum = 0;
    for (int i = 0; i < n; ++i)
    {
        csum += a[i];
        if (csum == sum / 3)
        {
            auto iter = upper_bound(ALL(b), i + 1);
            ans += distance(iter, b.end());
        }
    }

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