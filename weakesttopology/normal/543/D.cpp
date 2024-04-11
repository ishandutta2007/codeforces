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
    return (r + MOD) % MOD;
}

ll dfs(const vvi& E, vll& f, int u, int p)
{
    ll c = 1;
    for (auto v : E[u])
        if (v != p)
            c = (c * dfs(E, f, v, u)) % MOD;
    f[u] = (c + (u != p)) % MOD;
    return f[u];
}

vll ans, skip;

void dfs_spread(const vvi& E, vll& f, vi& p, int u)
{
    ans[u] = (f[u] + MOD) % MOD;

    if (f[u] == 0)
    {
        ll c = 1;

        int z = 0;
        while (f[E[u][z]])
            c = (c * f[E[u][z++]]) % MOD;
        for (int h = z + 1; h < SZ(E[u]); ++h)
            c = (c * f[E[u][h]]) % MOD;

        skip[E[u][z]] = c;

        for (auto v : E[u])
            if (v != E[u][z])
                skip[v] = 0;
    }
    else
        for (auto v : E[u])
            skip[v] = (f[u] * power(f[v], MOD - 2)) % MOD;

    for (auto v : E[u])
        if (v != p[u])
        {
            ll prev = f[v];
            p[v] = u;

            f[u] = (skip[v] + 1) % MOD;
            f[v] = ((f[v] - 1) * f[u]) % MOD;

            dfs_spread(E, f, p, v);
            f[v] = prev;
            f[u] = ans[u];
        }
}

int main()
{ _
    int n; cin >> n;

    vvi E(n);
    for (int u = 1; u < n; ++u)
    {
        int v; cin >> v; --v;
        E[u].pb(v), E[v].pb(u);
    }

    vll f(n, -1); vi p(n, 0); ans.assign(n, -1), skip.assign(n, -1);

    f[0] = dfs(E, f, 0, 0);
    dfs_spread(E, f, p, 0);

    for (auto x : ans)
        cout << x << " ";
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