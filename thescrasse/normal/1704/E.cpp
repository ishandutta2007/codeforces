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
        ll n, m; cin >> n >> m;

        vector<ll> val(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> val[i];
        }

        vector<vector<ll>> adj(n + 1, vector<ll>());
        vector<vector<ll>> adj_rev(n + 1, vector<ll>());
        for (ll i = 1; i <= m; i++) {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b); adj_rev[b].pb(a);
        }

        vector<bool> vis(n + 1, false);
        vector<ll> ts_order;
        function<void(ll)> toposort;
        toposort = [&](ll s) {
            if (vis[s]) return;
            vis[s] = true;
            for (auto u : adj[s]) toposort(u);
            ts_order.pb(s);
        };

        for (ll i = 1; i <= n; i++) toposort(i);

        vector<ll> flag(10, 0);

        for (ll sec = 1; sec <= n + 5; sec++) {
            flag[0] = 0;
            for (ll i = 0; i < n; i++) {
                if (val[ts_order[i]] == 0) continue;
                val[ts_order[i]]--; flag[0] = 1;
                for (auto u : adj[ts_order[i]]) val[u]++;
            }

            if (flag[0] == 0) {
                cout << sec - 1 << nl; break;
            }
        }

        if (flag[0] == 0) continue;

        reverse(ts_order.begin(), ts_order.end());

        for (ll i = 0; i < n; i++) {
            for (auto u : adj_rev[ts_order[i]]) val[ts_order[i]] = (val[ts_order[i]] + val[u]) % mod;
        }

        ll res = (n + 5 + val[ts_order[n - 1]]) % mod;

        cout << res << nl;
    }

    return 0;
}