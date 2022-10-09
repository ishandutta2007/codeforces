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
#define maxb 8202

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll i, i1, j, k, k1, t, n, m, res, b;
    vector<ll> flag(10, 0);

    cin >> n;
    vector<ll> a(n + 1, 0);
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto repr = [&](ll a, ll b) {
        return min(a, a ^ b);
    };

    vector<ll> dp(maxb, maxb - 1);
    vector<vector<ll>> nxt(maxb, vector<ll>());

    auto dec = [&](ll p) {
        ll a, b, r;
        a = p; b = dp[p]; r = repr(a, b);
        dp[p]--;
        a = p; b = dp[p]; r = repr(a, b);
        nxt[b].pb(a);
        // cout << "nxt push" _ b _ a << nl;
    };

    vector<ll> rs;

    auto upd = [&](ll p, ll x) {
        // cout << "upd" _ p _ x << nl;
        if (dp[p] == maxb - 1) rs.pb(p);
        while (dp[p] > x) dec(p);
    };

    auto visit = [&](ll p) {
        vector<ll> nx = nxt[p];
        // cout << "visit" _ p << nl;
        for (auto u : nx) {
            // cout << "u =" _ u << nl;
            upd(u, p); upd(u ^ p, p);
        }
        nxt[p].clear();
    };

    upd(0, 0);
    for (i = 1; i <= n; i++) visit(a[i]);

    sort(rs.begin(), rs.end());
    cout << rs.size() << nl;
    for (auto u : rs) cout << u << ' ';
    cout << nl;

    return 0;
}