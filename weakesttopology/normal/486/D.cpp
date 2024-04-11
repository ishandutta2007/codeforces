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

ll modpower(ll x, int p)
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

int n, d;
vi vis;
vvi E;

ll dfs_counter(int u, int p, int MAX, vi& a)
{
    ll c = 1;

    for (auto v : E[u])
        if (v != p && vis[v] && abs(MAX - a[v]) <= d)
            c = c * (1 + dfs_counter(v, u, MAX, a)) % MOD;

    return c;
}


int main()
{ _
    cin >> d >> n;
    E.assign(n, vi());
    vis.assign(n, 0);
    vi a(n); READ(a);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].pb(v);
        E[v].pb(u);
    }

    ll ans = 0;

    vi I(n);
    for (int i = 0; i < n; ++i)
        I[i] = i;
    sort(ALL(I), [&a](int u, int v) { return a[u] > a[v]; });

    for (int i = 0; i < n; ++i)
    {
        ans = (ans + dfs_counter(I[i], I[i], a[I[i]], a)) % MOD;
        vis[I[i]] = 1;
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