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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll bsl, bsm, bsu;

bool good(ll x) {
    ll i, k = 0;
    for (i = 1; i <= n; i++) {
        if (x - (k + 1) > a[i]) continue;
        if (k > b[i]) continue;
        k++;
    }

    return (k >= x);
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
            cin >> a[i] >> b[i];
        }

        bsl = 0; bsu = n + 1;
        while (bsl != bsu) {
            bsm = (bsl + bsu + 1) / 2;
            if (good(bsm)) bsl = bsm;
            else bsu = bsm - 1;
        }

        cout << bsl << nl;
    }

    return 0;
}