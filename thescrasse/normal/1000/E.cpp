// 1000E
// We Need More Bosses

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dist[maxn], be[maxn], tot[maxn], parent[maxn];
array<ll, 2> dp[maxn][2];
bool visited[maxn];
vector<ll> adj[maxn], tadj[maxn], f;

void dfs(ll s) {
    // cout << "s = " << s << nl;
    for (auto u : adj[s]) {
        // cout << "u = " << u << nl;
        if (parent[s] == u) continue;
        if (visited[u]) {
            if (dist[u] > dist[s]) continue;
            // cout << s << ' ' << u << nl;
            be[s]++; be[u]--;
            continue;
        }
        visited[u] = true;
        parent[u] = s;
        dist[u] = dist[s] + 1;
        tadj[s].pb(u); tadj[u].pb(s);
        dfs(u);
        be[s] += be[u];
    }
}

void brg(ll s) {
    for (auto u : tadj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        brg(u);
        if (dp[u][0][0] + be[u] > dp[s][0][0]) {
            // cout << "a " << s << ' ' << u << nl;
            dp[s][1] = dp[s][0];
            dp[s][0] = {dp[u][0][0] + be[u], u};
        } else if (dp[u][0][0] + be[u] > dp[s][1][0]) {
            // cout << "b " << s << ' ' << u << nl;
            dp[s][1] = {dp[u][0][0] + be[u], u};
        }
    }
}

void prt(ll s) {
    for (auto u : tadj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        if (dp[s][0][1] == u) {
            tot[u] = dp[s][1][0];
        } else {
            tot[u] = dp[s][0][0];
        }
        tot[u] = max(tot[u], tot[s]);
        tot[u] += be[u];
        prt(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    for (i = 1; i <= n; i++) {
        be[i] = 0; dp[i][0] = {0, 0}; dp[i][1] = {0, 0};
    }
    visited[1] = true; dist[1] = 0; dfs(1);

    for (i = 2; i <= n; i++) {
        visited[i] = false;
        if (be[i] == 0) be[i] = 1;
        else be[i] = 0;
    }
    brg(1);

    for (i = 2; i <= n; i++) visited[i] = false;
    prt(1);

    res = 0;
    for (i = 1; i <= n; i++) {
        res = max(res, tot[i]);
    }

    /* for (i = 1; i <= n; i++) {
        cout << i << ' ' << be[i] << ' ' << dp[i][0][0] << ' ' << dp[i][1][0] << ' ' << tot[i] << nl;
    } */

    cout << res;

    return 0;
}