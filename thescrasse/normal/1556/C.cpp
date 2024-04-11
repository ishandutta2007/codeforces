#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define y1 gnreongier

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll l, r, ts, ms;

ll nts(ll l1, ll r1, ll l2, ll r2, ll mv) {
    // cout << l1 _ r1 _ l2 _ r2 _ mv << nl;
    return max((ll)0, min(r1, r2 + mv) - max(l1, l2 + mv) + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 0) a[i] *= -1;
    }

    for (i = 1; i <= n; i++) {
        k = a[i]; m = a[i];
        for (j = i + 1; j <= n; j++) {
            if (k < 0) break;
            ts = k - a[i]; ms = m - a[i];
            if (a[j] < 0) res += nts(max((ll)1, -ms), a[i], 1, -a[j], -ts);
            // cout << i _ j _ ts _ ms _ res << nl;
            k += a[j]; m = min(m, k);
        }
    }

    cout << res << nl;

    return 0;
}