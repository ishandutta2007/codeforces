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
    int n, m, x, y; cin >> n >> m >> x >> y; --x, --y;
    vector<vpll> E(n);
    for (int j = 0; j < m; ++j)
    {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        E[u].pb(mp(v, w));
        E[v].pb(mp(u, w));
    }

    vi t(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> c[i];

    vvll dist(n, vll(n, LINF));
    for (int s = 0; s < n; ++s)
    {
        dist[s][s] = 0;
        priority_queue<pll, vpll, greater<pll>> pq; pq.push(mp(0, s));

        while (!pq.empty())
        {
            pll front = pq.top(); pq.pop();
            ll d = front.f, u = front.s;

            if (d > dist[s][u])
                continue;

            for (auto [v, w] : E[u])
                if (dist[s][u] + w < dist[s][v])
                {
                    dist[s][v] = dist[s][u] + w;
                    pq.push(mp(dist[s][v], v));
                }
        }
    }

    vector<vpll> E_cost(n);

    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            if (u != v && dist[u][v] <= t[u])
                E_cost[u].pb(mp(v, c[u]));


    vll cost(n, LINF); cost[x] = 0;
    priority_queue<pll, vpll, greater<pll>> pq; pq.push(mp(0, x));

    while (!pq.empty())
    {
        pll front = pq.top(); pq.pop();
        ll d = front.f, u = front.s;

        if (d > cost[u])
            continue;

        for (auto [v, w] : E_cost[u])
            if (cost[u] + w < cost[v])
            {
                cost[v] = cost[u] + w;
                pq.push(mp(cost[v], v));
            }
    }

    if (cost[y] == LINF)
        cout << -1 << endl;
    else
        cout << cost[y] << endl;

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