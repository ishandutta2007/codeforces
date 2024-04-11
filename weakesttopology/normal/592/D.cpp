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

int dfs(const vvi& E, const vi& T, int u, int p)
{
    int c = 0;

    for (auto v : E[u])
        if (v != p)
            c += dfs(E, T, v, u);

    if (T[u] || c)
        return c + 1;
    else
        return 0;
}

int main()
{ _
    int n, m; cin >> n >> m;

    vvi E(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].pb(v); E[v].pb(u);
    }

    vi T(n, 0);
    int t = INF;
    for (int j = 0; j < m; ++j)
    {
        int u; cin >> u; --u;
        T[u] = 1;
        t = min(t, u);
    }

    vi p(n, t);
    vi d(n, 0);

    queue<int> q; q.push(t);
    while (not q.empty())
    {
        int u = q.front(); q.pop();

        for (auto v : E[u])
            if (v != p[u])
            {
                p[v] = u;
                d[v] = d[u] + 1;
                if (T[v] && (d[v] > d[t] || (d[v] == d[t] && v < t)))
                    t = v;
                q.push(v);
            }
    }

    q.push(t);
    p.assign(n, t);
    d.assign(n, 0);
    int o = 0;
    while (not q.empty())
    {
        int u = q.front(); q.pop();

        for (auto v : E[u])
            if (v != p[u])
            {
                p[v] = u;
                d[v] = d[u] + 1;
                o = max(o, d[v] * T[v]);
                q.push(v);
            }
    }

    for (int u = 0; u < n; ++u)
        if (T[u] && d[u] == o)
            t = min(t, u);

    int x = 0;
    for (int u = 0; u < n; ++u)
        x = max(x, d[u] * T[u]);

    int ans = 2 * (dfs(E, T, t, t) - 1) - x;

    cout << t + 1 << endl << ans << endl;

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