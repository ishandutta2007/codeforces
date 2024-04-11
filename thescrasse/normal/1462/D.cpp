#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 3010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, tt;
vector<ll> dv;

bool solve(ll x) {
    if (tt / x > n) return false;

    // cout << "x = " << x << nl;

    ll k = 0;
    for (i = 1; i <= n; i++) {
        k += a[i];
        if (k > x) return false;
        if (k == x) k = 0;

        // cout << "k = " << k << nl;
    }

    if (k == 0) return true;
    return false;
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
        cin >> n; tt = 0; res = INF;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; tt += a[i];
        }

        dv.clear();
        for (i = 1; i * i <= tt; i++) {
            if (tt % i == 0) {
                dv.pb(i); dv.pb(tt / i);
            }
        }

        for (auto u : dv) {
            if (solve(u)) res = min(res, n - tt / u);
        }

        cout << res << nl;
    }

    return 0;
}