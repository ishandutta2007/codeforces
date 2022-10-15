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
    vector E(n, vector<pair<int, ii>>());
    for (int j = 0; j < m; ++j)
    {
        int x, y, z; cin >> x >> y >> z; --x, --y;
        E[x].pb(mp(y, mp(1, !z)));
        E[y].pb(mp(x, mp(1, !z)));
    }

    int s = 0;
    vii dist(n, mp(INF, 1)); dist[s] = mp(0, 0);
    priority_queue<pair<ii, int>, vector<pair<ii, int>>, greater<pair<ii, int>>> pq; pq.push(mp(mp(0, 0), s));

    vi p(n, -1);

    while (!pq.empty())
    {
        auto front = pq.top(); pq.pop();
        ii d = front.f;
        int u = front.s;

        if (d > dist[u])
            continue;

        for (auto [v, w] : E[u])
            if (mp(dist[u].f + w.f, dist[u].s + w.s) < dist[v])
            {
                dist[v] = mp(dist[u].f + w.f, dist[u].s + w.s);
                p[v] = u;
                pq.push(mp(dist[v], v));
            }
    }

    vector<pair<ii, int>> ans;
    set<ii> P;

    for (int v = n - 1; v != 0; v = p[v])
    {
        int u = p[v];

        if (dist[u].s < dist[v].s)
            ans.pb(mp(mp(u, v), 1));

        P.insert(mp(min(u, v), max(u, v)));
    }

    for (int u = 0; u < n; ++u)
        for (auto [v, w] : E[u])
            if (u < v && P.count(mp(u, v)) == 0 && not w.s)
                ans.pb(mp(mp(u, v), 0));

    cout << SZ(ans) << endl;
    for (auto [e, z] : ans)
        cout << e.f + 1 << " " << e.s + 1 << " " << z << endl;

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