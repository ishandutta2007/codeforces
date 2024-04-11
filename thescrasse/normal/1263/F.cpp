// 1263F
// Economic Difficulties

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n[2], m[2], res, flag[10], a, b, c[2][maxn], x;
ll parent[2][maxn], sp[2][maxn][15], dp[maxn][maxn], l, dist[2][maxn];
bool visited[2][maxn];
vector<ll> adj[2][maxn];

void dfs(ll ty, ll s) {
    ll i;
    for (auto u : adj[ty][s]) {
        if (visited[ty][u]) continue;
        visited[ty][u] = true; dist[ty][u] = dist[ty][s] + 1;
        parent[ty][u] = s; sp[ty][u][0] = s;
        i = 1;
        while (true) {
            if (dist[ty][u] < (1 << i)) break;
            sp[ty][u][i] = sp[ty][sp[ty][u][i - 1]][i - 1]; i++;
        }
        dfs(ty, u);
    }
}

ll lca(ll ty, ll a, ll b) {
    // cout << "lca " << ty << ' ' << a << ' ' << b << ' ';
    ll i, k;
    if (dist[ty][a] < dist[ty][b]) swap(a, b);
    k = dist[ty][a] - dist[ty][b];
    for (i = 15; i >= 0; i--) {
        if (k >= (1 << i)) {
            a = sp[ty][a][i]; k -= (1 << i);
        }
    }

    if (a == b) {
        // cout << a << nl;
        return a;
    }

    for (i = 15; i >= 0; i--) {
        k = (1 << i);
        if (k > dist[ty][a]) continue;
        if (sp[ty][a][i] != sp[ty][b][i]) {
            a = sp[ty][a][i]; b = sp[ty][b][i];
        }
    }

    // cout << parent[ty][a] << nl;
    return parent[ty][a];
}

void init(ll ty, ll s) {
    for (i = 1; i <= n[ty]; i++) visited[ty][i] = false;
    visited[ty][s] = true; dfs(ty, s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> k;
    for (i = 0; i < 2; i++) {
        cin >> n[i];
        for (j = 2; j <= n[i]; j++) {
            cin >> a; adj[i][a].pb(j); adj[i][j].pb(a);
        }
        for (j = 1; j <= k; j++) {
            cin >> c[i][j];
        }
    }

    init(0, 1); init(1, 1);

    for (i = 0; i <= n[0]; i++) {
        for (j = 0; j <= n[1]; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0; dp[1][0] = dist[0][c[0][1]]; dp[0][1] = dist[1][c[1][1]];
    for (i = 0; i <= k; i++) {
        for (j = 0; j <= k; j++) {
            a = c[0][i]; b = c[1][j];
            if (i > j + 1) {
                x = c[0][i - 1];
                dp[i][j] = dp[i - 1][j] + dist[0][a] - dist[0][lca(0, a, x)];
            } else if (i == j + 1) {
                for (l = 0; l < j; l++) {
                    x = c[0][l];
                    dp[i][j] = min(dp[i][j], dp[l][j] + dist[0][a] - dist[0][lca(0, a, x)]);
                }
            } else if (j == i + 1) {
                for (l = 0; l < i; l++) {
                    x = c[1][l];
                    dp[i][j] = min(dp[i][j], dp[i][l] + dist[1][b] - dist[1][lca(1, b, x)]);
                }
            } else if (j > i + 1) {
                x = c[1][j - 1];
                dp[i][j] = dp[i][j - 1] + dist[1][b] - dist[1][lca(1, b, x)];
            }
        }
    }

    /* for (i = 0; i < 2; i++) {
        for (j = 1; j <= n[i]; j++) {
            cout << i << ' ' << j << ' ' << dist[i][j] << nl;
        }
    }
    cout << nl;

    for (i = 0; i <= k; i++) {
        for (j = 0; j <= k; j++) {
            cout << i << ' ' << j << ' ' << dp[i][j] << nl;
        }
    } */

    res = INF;
    for (i = 0; i < k; i++) res = min({res, dp[i][k], dp[k][i]});

    cout << n[0] + n[1] - res - 2;

    return 0;
}