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
        ll n, x; cin >> n >> x;
        vector<ll> a(n + 1, 0);
        for (ll i = 1; i <= n; i++) cin >> a[i];

        ll l = INF, r = -INF, res = 0;
        for (ll i = 1; i <= n; i++) {
            l = min(l, a[i]); r = max(r, a[i]);
            if (r - l > 2 * x) {
                l = a[i]; r = a[i]; res++;
            }
        }

        cout << res << nl;
    }

    return 0;
}