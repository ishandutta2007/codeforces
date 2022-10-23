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
        vector<ll> a(n + 1, 0);
        ll tt = 0;
        for (ll i = 1; i <= n; i++) cin >> a[i], tt += a[i];

        if (tt % 2 != 0) {
            cout << -1 << nl; continue;
        }

        vector<ll> sgn(n + 1, 0);
        ll prev_imp = 0;
        ll parity = 1;
        for (ll i = 1; i <= n; i++) {
            if (a[i] == 0) {
                sgn[i] = -sgn[i - 1];
            } else {
                if (parity == 1) {
                    sgn[i] = 1;
                } else {
                    if (prev_imp == a[i]) sgn[i] = -1;
                    else sgn[i] = 1;
                }

                prev_imp = a[i]; parity ^= 1;
            }

            if (sgn[i] == -1 && a[i] != 0 && i != 1 && a[i - 1] == 0) {
                sgn[i - 1] = 1;
            }
        }

        vector<array<ll, 2>> ans;
        ll l = 1;
        for (ll i = 2; i <= n + 1; i++) {
            if (i == n + 1 || sgn[i] == 1) {
                ans.pb({l, i - 1}); l = i;
            }
        }

        cout << ans.size() << nl;
        for (auto [x, y] : ans) cout << x _ y << nl;
    }

    return 0;
}