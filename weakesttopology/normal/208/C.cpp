#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n, m; cin >> n >> m;
    vvi E(n); vii F(m);
    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].pb(v), E[v].pb(u);
        F[j] = mp(u, v);
    }

    vvll dist(2, vll(n, INF)); dist[0][0] = dist[1][n - 1] = 0;
    vvll ways(2, vll(n, 0));
    ways[0][0] = 1, ways[1][n - 1] = 1;

    queue<int> q; q.push(0);
    while (not q.empty())
    {
        int u = q.front(); q.pop();

        for (auto v : E[u])
            if (dist[0][u] < dist[0][v])
            {
                if (dist[0][v] == INF)
                    q.push(v);

                dist[0][v] = dist[0][u] + 1;
                ways[0][v] += ways[0][u];
            }
    }

    q.push(n - 1);
    while (not q.empty())
    {
        int u = q.front(); q.pop();

        for (auto v : E[u])
            if (dist[1][u] < dist[1][v])
            {
                if (dist[1][v] == INF)
                    q.push(v);

                dist[1][v] = dist[1][u] + 1;
                ways[1][v] += ways[1][u];
            }
    }

    double ans = 0;

    for (int u = 1; u < n - 1; ++u)
        if (dist[0][u] + dist[1][u] == dist[0][n - 1])
            ans = max(ans, double(2) * ways[0][u] * ways[1][u]);

    ans = max(double(1), ans / ways[0][n - 1]);

    cout << setprecision(10) << fixed;
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