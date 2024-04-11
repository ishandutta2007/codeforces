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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        // cout << "t =" _ t << nl;
        ll i, i1, j, k, k1, n, m, res, a, b;
        vector<ll> flag(10, 0);

        cin >> n;

        vector<vector<vector<ll>>> mt(n + 2, vector<vector<ll>>(n + 2, vector<ll>(n + 2, 0)));
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                for (k = 1; k <= n; k++) {
                    char c; cin >> c;
                    if (c == '1') mt[i][j][k] = 1, mt[j][i][k] = 1;
                }
            }
        }

        vector<bool> vis(n + 2, false);
        vector<vector<ll>> dist(n + 2, vector<ll>(n + 2, 0));

        function<void(int, int)> dfs;
        dfs = [&](ll s, ll p) {
            // cout << "dfs" _ s _ p << nl;
            ll i;
            if (vis[s]) return;
            vis[s] = true; dist[s][p] = 1; dist[p][s] = 1;
            for (i = 1; i <= n; i++) {
                if (mt[p][i][s] == 1) dfs(i, s);
            }
        };

        auto fws = [&]() {
            ll i, j, k;
            for (k = 1; k <= n; k++) {
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        };

        auto good = [&]() {
            ll i, j, k;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (dist[i][j] == INF) return false;
                    for (k = 1; k <= n; k++) {
                        if (i == j) continue;
                        if ((dist[i][k] == dist[j][k]) ^ (mt[i][j][k] == 1)) {
                            // cout << "error" _ i _ j _ k << nl;
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        auto solve = [&](ll a, ll b) {
            ll i, j, k;
            for (i = 1; i <= n; i++) vis[i] = false;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (i == j) dist[i][j] = 0;
                    else dist[i][j] = INF;
                }
            }
            dfs(a, b); dfs(b, a); fws();
            return good();
        };

        auto send = [&]() {
            ll i, j;
            for (i = 1; i <= n; i++) {
                for (j = i + 1; j <= n; j++) {
                    if (dist[i][j] == 1) cout << i _ j << nl;
                }
            }
        };

        auto dbg = [&]() {
            ll i, j;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    cout << dist[i][j] << ' ';
                }
                cout << nl;
            }
        };

        for (i = 2; i <= n; i++) {
            // cout << "i =" _ i << nl;
            if (solve(1, i)) {
                cout << "Yes" << nl; send(); break;
            }
            // dbg();
        }

        if (i == n + 1) cout << "No" << nl;
    }

    return 0;
}