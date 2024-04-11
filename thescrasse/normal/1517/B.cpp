#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll cr[maxn], x, y, rs[maxn][maxn];
vector<ll> adj[maxn];
vector<array<ll, 3>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m; v.clear(); v.pb({-INF, 0, 0});
        for (i = 1; i <= n; i++) {
            adj[i].clear(); adj[i].pb(-INF); cr[i] = m;
            for (j = 1; j <= m; j++) {
                cin >> a; adj[i].pb(a);
            }
        }


        for (i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                a = adj[i][j]; v.pb({a, i, j});
            }
        }

        sort(v.begin(), v.end());
        // for (auto u : v) cout << u[0] _ u[1] _ u[2] << nl;

        /* for (i = 1; i <= n; i++) {
            for (auto u : adj[i]) cout << u << ' ';
            cout << nl;
        } */

        for (i = 1; i <= m; i++) {
            x = v[i][1]; y = v[i][2];
            // cout << x _ y << nl;
            for (j = 1; j <= n; j++) {
                if (j == x) {
                    rs[j][i] = adj[j][y];
                } else {
                    rs[j][i] = adj[j][cr[j]]; cr[j]--;
                }
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << rs[i][j] << ' ';
            }
            cout << nl;
        }
    }

    return 0;
}