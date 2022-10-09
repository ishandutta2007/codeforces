#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll g;
vector<ll> adj[maxn];

void rst() {
    ll i;
    g = 0;
    for (i = 0; i <= n; i++) adj[i].clear();
}

ll solve(ll p) {
    ll i, k, mx, rs = 0;
    for (i = 0; i < g; i++) {
        k = 0; mx = -INF;
        if (adj[i].size() < p) return -INF;
        for (auto u : adj[i]) k += u;
        if (p == 0) mx = max(mx, k);
        for (j = 0; j < adj[i].size(); j++) {
            k -= (2 * adj[i][j]);
            if (j % 2 != p) mx = max(mx, k);
        }
        // cout << "i, mx =" _ i _ mx << nl;
        rs += mx;
    }
    return rs;
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
        cin >> n >> m; rst();
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= m; i++) {
            cin >> b;
            if (g == 0) g = b;
            else g = __gcd(g, b);
        }

        for (i = 1; i <= n; i++) adj[i % g].pb(a[i]);

        for (i = 0; i < g; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        // cout << solve(0) _ solve(1) << nl;
        res = max(solve(0), solve(1));

        cout << res << nl;
    }

    return 0;
}