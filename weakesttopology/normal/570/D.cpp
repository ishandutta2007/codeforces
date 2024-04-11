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

int ct = 0;
vi L, R, d;
void dfs(const vvi& E, int u)
{
    L[u] = ct++;
    for (auto v : E[u])
    {
        d[v] = 1 + d[u];
        dfs(E, v);
    }
    R[u] = ct;
}

int main()
{ _
    int n, m; cin >> n >> m;
    vvi E(n);
    for (int u = 1; u < n; ++u)
    {
        int v; cin >> v; --v;
        E[v].pb(u);
    }

    L.assign(n, 0), R.assign(n, 0), d.assign(n, 1);
    dfs(E, 0);

    vi f(n);
    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        f[i] = 1 << (c - 'a');
    }

    vi I(n, 0); iota(ALL(I), 0);
    sort(ALL(I), [](int u, int v){ return mp(d[u], L[u]) < mp(d[v], L[v]); });

    vii info(n);
    for (int i = 0; i < n; ++i)
        info[i] = mp(d[I[i]], L[I[i]]);

    vi XOR(n, 0); XOR[0] = f[I[0]];
    for (int u = 1; u < n; ++u)
        XOR[u] = f[I[u]] ^ XOR[u - 1];

    for (int j = 0; j < m; ++j)
    {
        int v, h; cin >> v >> h; --v;

        auto l = lower_bound(ALL(info), mp(h, L[v]));
        auto r = upper_bound(ALL(info), mp(h, R[v] - 1));

        int X = XOR[distance(info.begin(), --r)];
        if (l != info.begin())
            X ^= XOR[distance(info.begin(), --l)];

        if (__builtin_popcount(X) <= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

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