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

ll ask(ll x) {
    cout << "?" _ x << nf;
    ll y; cin >> y; return y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> degree(n + 1, 0), ans(n + 1, 0);
        priority_queue<array<ll, 2>> pq;
        vector<vector<ll>> adj(n + 1, vector<ll>());
        vector<bool> vis(n + 1, false);
        vector<bool> vis_dfs(n + 1, false);
        for (ll i = 1; i <= n; i++) {
            cin >> degree[i]; pq.push({degree[i], i});
        }

        while (!pq.empty()) {
            auto [deg, s] = pq.top(); pq.pop();
            if (vis[s]) continue;
            vis[s] = true;
            for (ll i = 1; i <= deg; i++) {
                ll u = ask(s);
                adj[s].pb(u); adj[u].pb(s);
                if (vis[u]) break;
                vis[u] = true;
            }
        }

        function<void(ll, ll)> dfs = [&](ll s, ll c) {
            if (vis_dfs[s]) return;
            vis_dfs[s] = true; ans[s] = c;
            for (auto u : adj[s]) dfs(u, c);
        };

        ll curr = 0;
        for (ll i = 1; i <= n; i++) {
            if (vis_dfs[i]) continue;
            curr++; dfs(i, curr);
        }

        cout << "!" << ' ';
        for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << nf;
    }

    return 0;
}