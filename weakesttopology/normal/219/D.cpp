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

int dfs(const vvii& E, int u, int p)
{
    int c = 0;

    for (auto [v, d] : E[u])
        if (v != p)
            c += dfs(E, v, u) + !d;

    return c;
}

void dfs_inv(const vvii& E, vi& inv, int u, int p)
{
    for (auto [v, d] : E[u])
        if (v != p)
        {
            inv[v] = inv[u] + (d ? 1 : -1);
            dfs_inv(E, inv, v, u);
        }
}

int main()
{ _
    int n; cin >> n;

    vvii E(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int s, t; cin >> s >> t; --s, --t;

        E[s].pb(mp(t, 1));
        E[t].pb(mp(s, 0));
    }

    vi inv(n, 0); inv[0] = dfs(E, 0, 0);
    dfs_inv(E, inv, 0, 0);

    vi I(n);
    for (int i = 0; i < n; ++i)
        I[i] = i;

    sort(ALL(I), [&inv](int i, int j){ return mp(inv[i], i) < mp(inv[j], j); });

    cout << inv[I[0]] << endl;

    for (int i = 0; inv[I[i]] == inv[I[0]]; ++i)
        cout << I[i] + 1 << " ";
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