#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<ll> adj[maxn];
bool visited[maxn];
vector<ll> ts;

void dfs(ll s) {
    // cout << "dfs " << s << nl;
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adj[s]) dfs(u);
    ts.pb(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; res = 0;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            adj[i].pb(b[i]);
            /* if (a[i] > 0) {
                adj[i].pb(b[i]);
            } else {
                adj[b[i]].pb(i);
            } */
        }
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    reverse(ts.begin(), ts.end());

    for (auto u : ts) {
        if (b[u] != -1 && a[u] > 0) a[b[u]] += a[u];
    }

    for (i = 1; i <= n; i++) {
        adj[i].clear(); visited[i] = false;
    }
    ts.clear();

    for (i = 1; i <= n; i++) {
        res += a[i];
        if (b[i] != -1) {
            if (a[i] > 0) {
                adj[i].pb(b[i]);
            } else {
                adj[b[i]].pb(i);
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    reverse(ts.begin(), ts.end());

    cout << res << nl;
    for (auto u : ts) cout << u << ' ';

    return 0;
}