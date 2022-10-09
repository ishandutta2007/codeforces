#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p[maxn], h[maxn], parent[maxn], ps[maxn], hp[maxn];
vector<ll> adj[maxn];
bool visited[maxn];

void dfs(ll s) {
    ps[s] = p[s];
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        parent[u] = s;
        visited[u] = true;
        dfs(u);
        ps[s] += ps[u];
    }
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
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            adj[i].clear(); visited[i] = false;
            cin >> p[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> h[i];
        }
        for (i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }

        visited[1] = true; parent[1] = -1; dfs(1);

        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            if (abs(h[i]) > ps[i]) flag[0] = 0;
            if (abs(h[i] + ps[i]) % 2) flag[0] = 0;
            hp[i] = (h[i] + ps[i]) / 2;
        }

        /* for (i = 1; i <= n; i++) {
            cout << ps[i] << ' ';
        }
        cout << nl; */

        for (i = 1; i <= n; i++) {
            k = 0;
            for (auto u : adj[i]) {
                if (u == parent[i]) continue;
                k += hp[u];
            }

            // cout << i << ' ' << k << ' ' << ps[i] << nl;

            if (k > hp[i]) flag[0] = 0;
        }

        /* for (i = 1; i <= n; i++) {
            cout << hp[i] << ' ';
        }
        cout << nl; */

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}