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

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].pb(v), E[v].pb(u);
    }

    auto dijsktra = [&E, &n](int s)
    {
        vi dist(n, INF); dist[s] = 0;
        priority_queue<ii, vii, greater<ii>> pq; pq.push(mp(0, s));

        while (!pq.empty())
        {
            ii front = pq.top(); pq.pop();
            int d = front.f, u = front.s;

            if (d > dist[u])
                continue;

            for (auto v : E[u])
                if (dist[u] + 1 < dist[v])
                {
                    dist[v] = dist[u] + 1;
                    pq.push(mp(dist[v], v));
                }
        }

        return dist;
    };

    int s[2], t[2], l[2];

    vvi dist(n);
    for (int u = 0; u < n; ++u)
        dist[u] = dijsktra(u);

    int ans = m;

    for (int i = 0; i < 2; ++i)
    {
        cin >> s[i] >> t[i] >> l[i]; --s[i], --t[i];

        int d = dist[s[i]][t[i]];

        if (d > l[i])
        {
            cout << -1 << endl;
            exit(0);
        }
        ans -= d;
    }

    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
        {
            int d = 0;
            for (int i = 0; i < 2; ++i)
                d += dist[s[i]][u];
            d += dist[u][v];
            for (int i = 0; i < 2; ++i)
                d += dist[v][t[i]];

            int e[2] = { 0, 0 };
            for (int i = 0; i < 2; ++i)
                e[i] = dist[s[i]][u] + dist[u][v] + dist[v][t[i]];

            if (e[0] <= l[0] && e[1] <= l[1])
                ans = max(ans, m - d);
        }

    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
        {
            int d = 0;
            d += dist[s[0]][u];
            d += dist[t[0]][v];
            d += dist[s[1]][v];
            d += dist[u][t[1]];
            d += dist[u][v];

            int e[2] = { 0, 0 };
            e[0] = dist[s[0]][u] + dist[u][v] + dist[v][t[0]];
            e[1] = dist[s[1]][v] + dist[v][u] + dist[u][t[1]];

            if (e[0] <= l[0] && e[1] <= l[1])
                ans = max(ans, m - d);
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