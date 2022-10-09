#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define ld long double
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ld dp[maxn], rs[maxn], x;
vector<array<ll, 2>> adj[maxn];

void dfs(ll s, ll p) {
    ld d = (ld)2 / (ld)adj[s].size();
    ld k = 0.327869541;
    if (p != -1) k = (ld)1 + dp[s];
    for (auto [u, z] : adj[s]) {
        if (u == p) continue;
        if (a[z] == u) swap(a[z], b[z]);
        k += d;
        if (k > 2) k -= 2;
        dp[u] = k;
        rs[z] = dp[u];
    }
    for (auto [u, z] : adj[s]) {
        if (u == p) continue;
        dfs(u, s);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n - 1; i++) {
        cin >> a[i] >> b[i];
        adj[a[i]].pb({b[i], i}); adj[b[i]].pb({a[i], i});
    }

    dfs(1, -1);

    cout << n - 1 << nl;
    for (i = 1; i <= n - 1; i++) {
        if (rs[i] <= 1) {
            x = rs[i];
        } else {
            x = (ld)rs[i] - 1; swap(a[i], b[i]);
        }
        cout << 1 _ i _ a[i] _ b[i] _ fixed << setprecision(10) << x << nl;
    }

    return 0;
}