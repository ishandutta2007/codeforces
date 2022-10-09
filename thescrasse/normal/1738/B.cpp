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
        ll n, k; cin >> n >> k;
        vector<ll> a(n + 1, 0);
        for (ll i = n - k + 1; i <= n; i++) cin >> a[i];

        if (k == 1) {
            cout << "Yes" << nl; continue;
        }

        for (ll i = n - k; i >= 0; i--) a[i] = 2 * a[i + 1] - a[i + 2];

        /* for (ll i = 0; i <= n; i++) cout << a[i] << ' ';
        cout << nl; */

        ll flag = 1;
        if (a[0] > 0) flag = 0;
        for (ll i = n - k + 2; i <= n - 1; i++) {
            if (a[i] - a[i - 1] > a[i + 1] - a[i]) flag = 0;
        }

        if (flag == 1) cout << "Yes" << nl;
        else cout << "No" << nl;
    }

    return 0;
}