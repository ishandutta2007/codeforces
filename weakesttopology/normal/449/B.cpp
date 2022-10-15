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
    int n, m, k; cin >> n >> m >> k;
    vvii E(n); vi d(n, 0);
    for (int j = 0; j < m; ++j)
    {
        int u, v, x; cin >> u >> v >> x; --u, --v;
        E[u].pb(mp(v, x)); E[v].pb(mp(u, x));
        ++d[u], ++d[v];
    }

    set<int> S;
    for (int l = 0; l < k; ++l)
    {
        int s, y; cin >> s >> y; --s;
        E[0].pb(mp(s, y));
        E[s].pb(mp(0, y));

        S.insert(s);
    }

    vll dist(n, LINF); dist[0] = 0;
    priority_queue<pll, vpll, greater<pll>> pq; pq.push(mp(0, 0));

    while (!pq.empty())
    {
        pll front = pq.top(); pq.pop();
        ll d = front.f, u = front.s;

        if (d > dist[u])
            continue;

        for (auto [v, w] : E[u])
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(mp(dist[v], v));
            }
    }

    int ans = 0;

    for (auto u : S)
    {
        for (int i = 0; i < d[u]; ++i)
        {
            int v, w; tie(v, w) = E[u][i];

            if (dist[v] + w <= dist[u])
            {
                ++ans;
                break;
            }
        }

        ans += SZ(E[u]) - d[u] - 1;
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