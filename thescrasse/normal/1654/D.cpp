#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll f[maxn], mn[maxn], vl[maxn], nv[maxn], x, y;
bool vis[maxn];
vector<ll> pr[maxn];
vector<array<ll, 3>> adj[maxn];

ll fxp(ll b, ll e) {
    ll r = 0;
    if (e == 0) return 1;
    if (e % 2) {
        r = fxp(b, e - 1); return (b * r) % mod;
    } else {
        r = fxp(b, e / 2); return (r * r) % mod;
    }
}

ll inv(ll x) {
    return fxp(x, mod - 2);
}

void dfs(ll s) {
    vis[s] = true;
    for (auto [u, x, y] : adj[s]) {
        if (vis[u]) continue;
        vl[u] = vl[s];
        for (auto p : pr[y]) {
            f[p]++; vl[u] = (vl[u] * p) % mod;
        }
        for (auto p : pr[x]) {
            f[p]--; vl[u] = (vl[u] * nv[p]) % mod;
            mn[p] = min(mn[p], f[p]);
        }
        dfs(u);
        for (auto p : pr[x]) f[p]++;
        for (auto p : pr[y]) f[p]--;
    }
}

void rst() {
    ll i;
    for (i = 1; i <= n; i++) {
        vis[i] = false; adj[i].clear();
    }
    res = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (i = 2; i < maxn; i++) {
        if (!pr[i].empty()) continue;
        for (j = i; j < maxn; j += i) {
            k = j;
            while (k % i == 0) {
                pr[j].pb(i); k /= i;
            }
        }
    }

    for (i = 1; i < maxn; i++) nv[i] = inv(i);

    cin >> t;
    while (t--) {
        cin >> n; rst();
        for (i = 1; i <= n - 1; i++) {
            cin >> a >> b >> x >> y;
            adj[a].pb({b, x, y}); adj[b].pb({a, y, x});
        }

        vl[1] = 1; dfs(1);

        for (i = 1; i <= n; i++) {
            // cout << i _ vl[i] << nl;
            res = (res + vl[i]) % mod;
        }

        for (i = 1; i <= n; i++) {
            for (auto [u, x, y] : adj[i]) {
                for (auto p : pr[x]) {
                    for (j = 1; j <= -mn[p]; j++) res = (res * p) % mod;
                    f[p] = 0; mn[p] = 0;
                }
            }
        }

        cout << res << nl;
    }

    return 0;
}