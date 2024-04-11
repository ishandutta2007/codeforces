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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll bsl, bsm, bsu;

bool good(ll x) {
    ll r;
    if (x <= k) {
        r = (x * (x + 1)) / 2;
    } else {
        x = 2 * k - 1 - x;
        r = k * k - (x * (x + 1)) / 2;
    }
    return (r <= m);
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
        cin >> k >> m; m--;

        bsl = 0; bsu = 2 * k - 1;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            if (!good(bsm)) bsu = bsm;
            else bsl = bsm + 1;
        }

        cout << bsl << nl;
    }

    return 0;
}