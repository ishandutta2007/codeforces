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
ll dp[maxn][10], c, d;
vector<ll> adj[4];

void upd(ll l, array<ll, 3> f) {
    ll i, d1, j, s;
    vector<ll> v;
    for (i = 1; i <= 3; i++) {
        if (adj[i].size() < f[i - 1]) return;
    }

    for (i = 1; i <= 3; i++) {
        for (j = 0; j < f[i - 1]; j++) {
            v.pb(adj[i][j]);
        }
    }
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());
    s = v.size(); d1 = 0;
    for (auto u : v) d1 += u;

    // cout << "upd " << f[0] _ f[1] _ f[2] _ d1 << nl;

    for (j = 0; j <= 9; j++) {
        if (s == 0) dp[l][j] = max(dp[l][j], dp[l - 1][j]);
        else dp[l][j] = max(dp[l][j], dp[l - 1][(j - s + 10) % 10] + d1 + (j < s) * v[0]);
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

    for (i = 0; i < maxn; i++) {
        for (j = 0; j <= 9; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;

    for (i = 1; i <= n; i++) {
        cin >> k;
        for (j = 0; j <= 3; j++) adj[j].clear();
        for (j = 1; j <= k; j++) {
            cin >> c >> d; adj[c].pb(d);
        }

        for (j = 0; j <= 3; j++) {
            sort(adj[j].begin(), adj[j].end());
            reverse(adj[j].begin(), adj[j].end());
        }
        upd(i, {0, 0, 0});
        upd(i, {1, 0, 0});
        upd(i, {2, 0, 0});
        upd(i, {3, 0, 0});
        upd(i, {0, 1, 0});
        upd(i, {1, 1, 0});
        upd(i, {0, 0, 1});
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 0; j <= 9; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    res = 0;
    for (j = 0; j <= 9; j++) res = max(res, dp[n][j]);

    cout << res << nl;

    return 0;
}