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
    vvii E(n);

    for (int j = 0; j < m; ++j)
    {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        E[a].pb(mp(b, c)), E[b].pb(mp(a, c));
    }

    vvi t(n);
    for (int i = 0; i < n; ++i)
    {
        int k; cin >> k;
        t[i].assign(k, 0);
        READ(t[i]);
    }

    vi dist(n, INF); dist[0] = 0;
    priority_queue<ii, vii, greater<ii>> pq; pq.push(mp(0, 0));

    while (!pq.empty())
    {
        ii front = pq.top(); pq.pop();
        int d = front.f, u = front.s;

        if (d > dist[u])
            continue;

        for (auto [v, w] : E[u])
        {
            int a = 0;

            if (SZ(t[u]) && t[u][0] <= dist[u])
            {
                int s = 0;
                for (int z = n; z; z >>= 1)
                    while (s + z < SZ(t[u]) && t[u][s + z] <= dist[u])
                        s += z;

                if (t[u][s] == dist[u])
                {
                    int e = s;
                    for (int z = n; z; z >>= 1)
                        while (e + z < SZ(t[u]) && t[u][e + z] <= dist[u] + e + z - s + 1)
                            e += z;
                    a += e - s + 1;
                }
            }

            if (dist[u] + w + a < dist[v])
            {
                dist[v] = dist[u] + w + a;
                pq.push(mp(dist[v], v));
            }
        }
    }

    int ans = dist[n - 1] == INF ? -1 : dist[n - 1];

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