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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

bool good(ll x) {
    ll i, sz;
    vector<ll> v;
    v.pb(0);
    for (i = 1; i <= n; i++) {
        if (a[i] != x) v.pb(a[i]);
    }

    sz = (ll)v.size() - 1;
    for (i = 1; i <= sz; i++) {
        if (v[i] != v[sz - i + 1]) return false;
    }

    return true;
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

        k = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] != a[n - i + 1]) {
                k = i; break;
            }
        }

        if (k == 0) {
            cout << "YES" << nl; continue;
        }

        if (good(a[i]) || good(a[n - i + 1])) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}