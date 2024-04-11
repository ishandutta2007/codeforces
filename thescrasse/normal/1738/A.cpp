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
        ll n; cin >> n;
        vector<ll> a(n + 1, 0), b(n + 1, 0), x, y;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        for (ll i = 1; i <= n; i++) {
            cin >> b[i];
            if (a[i] == 0) x.pb(b[i]);
            else y.pb(b[i]);
        }

        sort(x.begin(), x.end()); reverse(x.begin(), x.end());
        sort(y.begin(), y.end()); reverse(y.begin(), y.end());

        ll ans = 0;
        for (auto u : x) ans += u;
        for (auto u : y) ans += u;

        ll m = min(x.size(), y.size());
        if ((!x.empty()) && (!y.empty())) ans += max(x[m - 1], y[m - 1]);
        if ((!x.empty()) && (!y.empty()) && x.size() != y.size()) ans += min(x[m - 1], y[m - 1]);
        for (ll i = 0; i < m - 1; i++) ans += (x[i] + y[i]);

        cout << ans << nl;
    }

    return 0;
}