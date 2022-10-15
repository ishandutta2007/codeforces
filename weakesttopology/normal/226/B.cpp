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

vll a, sum;
int n;

ll qsum(int i, int j)
{
    if (i == 0)
        return sum[j];
    else
        return sum[j] - sum[i - 1];
}

ll power(ll x, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r *= x;
        p >>= 1;
        x = (x * x);
    }
    return r;
}

ll cost(int k)
{
    ll c = 0;
    for (ll level = 1, s = 0; s < n; s = s + power(k, level), ++level)
        c += level * qsum(s + 1, min(s + power(k, level), n - 1LL));
    return c;
}

int main()
{ _
    cin >> n;

    a.assign(n, 0); READ(a);
    sort(a.rbegin(), a.rend());

    sum = a;
    for (int i = 1; i < n; ++i)
        sum[i] += sum[i - 1];

    int N = 1e5;
    vll c(N + 1);
    for (int k = 1; k < n; ++k)
        c[k] = cost(k);
    for (int k = n - 1; k <= N; ++k)
        c[k] = c[n - 1];

    int q; cin >> q;
    while (q--)
    {
        int k; cin >> k;
        cout << c[k] << " ";
    }
    cout << endl;

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