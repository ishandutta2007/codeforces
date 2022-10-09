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
vector<array<ll, 4>> dp[maxn];

array<ll, 3> ins(array<ll, 4> a, ll x) {
    array<ll, 3> b = {a[0], a[1], INF};
    if (x < a[0]) b[0] = x;
    else if (x < a[1]) b[1] = x;
    else b[2] = x;
    return b;
}

vector<array<ll, 4>> upd(vector<array<ll, 4>> v, ll x) {
    ll i, y, mx = -INF - 1;
    vector<array<ll, 4>> w, rs;
    for (i = 0; i < v.size(); i++) {
        array<ll, 4> u = v[i];
        for (y = -x; y <= x; y += (2 * x)) {
            array<ll, 3> b = ins({u[0], u[1]}, y);
            if (b[2] < INF) continue;
            w.pb({b[0], b[1], y, i});
        }
    }

    sort(w.begin(), w.end()); reverse(w.begin(), w.end());
    for (auto u : w) {
        if (u[1] > mx) rs.pb(u);
        mx = max(mx, u[1]);
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
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        dp[0].clear(); dp[0].pb({INF, INF, -1, -1});
        for (i = 1; i <= n; i++) dp[i] = upd(dp[i - 1], a[i]);

        if (dp[n].empty()) {
            cout << "NO" << nl; continue;
        }

        cout << "YES" << nl; k = 0;
        for (i = n; i >= 1; i--) {
            a[i] = dp[i][k][2]; k = dp[i][k][3];
        }

        for (i = 1; i <= n; i++) cout << -a[i] << ' ';
        cout << nl;
    }

    return 0;
}