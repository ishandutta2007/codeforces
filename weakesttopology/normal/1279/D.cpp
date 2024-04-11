#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];

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
    ll z = 1;

    while (p > 0)
    {
        if (p & 1)
            z = (z * x) % MOD;

        p = p >> 1;
        x = (x * x) % MOD;
    }

    return z;
}

int main()
{ _
    ll n; cin >> n;

    vi k(n);
    vvi K(n, vi());
    map<ll, ll> H;

    for (ll i = 0; i < n; ++i)
    {
        cin >> k[i];
        for (ll j = 0; j < k[i]; ++j)
        {
            ll a; cin >> a;
            K[i].pb(a);
            H[a]++;
        }
    }

    vll inv(n, 0);
    for (ll i = 0; i < n; ++i)
        inv[i] = power(k[i], MOD - 2);

    ll sum = 0;
    for (ll x = 0; x < n; ++x)
    {
        ll S = 0;
        for (auto y : K[x])
            S = (S + H[y]) % MOD;

        sum = (sum + (inv[x] * S) % MOD) % MOD;
    }
    ll ans = (power((n * n) % MOD, MOD - 2) * sum) % MOD;
    cout << ans << endl;

    exit(0);
}