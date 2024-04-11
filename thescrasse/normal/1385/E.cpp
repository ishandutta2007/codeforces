#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, f, p[maxn];
vector<ll> adj[maxn];
ll visited[maxn];
vector<ll> ts;
vector<array<ll, 3>> rm;

void dfs(ll s) {
    if (visited[s] == 1) flag[0] = 0;
    if (visited[s] != 0) return;
    visited[s] = 1;
    for (auto u : adj[s]) dfs(u);
    visited[s] = 2; ts.pb(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        flag[0] = 1; rm.clear(); ts.clear();
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            adj[i].clear(); visited[i] = 0;
        }
        for (i = 0; i < m; i++) {
            cin >> f >> a >> b;
            rm.pb({f, a, b});
            if (f == 1) adj[a].pb(b);
        }
        for (i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }

        reverse(ts.begin(), ts.end());

        if (flag[0] == 0) {
            cout << "NO" << nl; continue;
        }

        cout << "YES" << nl;
        for (i = 0; i < n; i++) {
            p[ts[i]] = i;
        }

        for (auto u : rm) {
            if (u[0] == 1) {
                cout << u[1] << ' ' << u[2] << nl;
            } else {
                if (p[u[1]] > p[u[2]]) {
                    cout << u[2] << ' ' << u[1] << nl;
                } else {
                    cout << u[1] << ' ' << u[2] << nl;
                }
            }
        }
    }

    return 0;
}