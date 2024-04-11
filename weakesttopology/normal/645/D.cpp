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
    int n, m; cin >> n >> m;

    vvi E(n);

    map<ii, int> H;

    vi d(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].pb(v);
        H[mp(u, v)] = j;
        d[v]++;
    }

    queue<int> q;
    for (int u = 0; u < n; ++u)
        if (d[u] == 0)
            q.push(u);

    vi x;
    while (not q.empty())
    {
        int u = q.front(); q.pop();
        x.push_back(u);

        for (auto v : E[u])
        {
            --d[v];
            if (d[v] == 0)
                q.push(v);
        }
    }

    bool unique = true;

    int k = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        auto iter = find(ALL(E[x[i]]), x[i + 1]);

        if (iter == E[x[i]].end())
            unique = false;
        else
            k = max(k, H[mp(x[i], x[i + 1])]);
    }

    if (not unique)
    {
        cout << -1 << endl;
        exit(0);
    }

    cout << k + 1 << endl;

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