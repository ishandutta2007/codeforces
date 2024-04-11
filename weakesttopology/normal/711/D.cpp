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

int dfs(const vvi& E, vi& h, int u, int p)
{
    int r = 0;

    for (auto v : E[u])
    {
        if (h[v] == -1)
        {
            h[v] = h[u] + 1;
            r = max(r, dfs(E, h, v, u));
        }
        else if (v != p)
            r = max(r, h[u] - h[v] + 1);
    }

    return r;
}

int main()
{ _
    int n; cin >> n;

    vvi E(n);
    for (int u = 0; u < n; ++u)
    {
        int v; cin >> v; --v;
        E[u].pb(v);
        E[v].pb(u);
    }

    ll MOD = 1e9 + 7;

    ll ans = 1;

    vi h(n, -1);

    int z = 0;

    for (int u = 0; u < n; ++u)
    {
        if (h[u] != -1)
            continue;

        h[u] = 0;
        int c = dfs(E, h, u, u);
        if (c == 0)
            c = 2;
        z += c;

        ll x = 1;
        for (int i = 0; i < c; ++i)
            x = (2 * x) % MOD;
        x = (x - 2) % MOD;

        ans = (ans * x) % MOD;
    }

    for (int i = z; i < n; ++i)
        ans = (2 * ans) % MOD;

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