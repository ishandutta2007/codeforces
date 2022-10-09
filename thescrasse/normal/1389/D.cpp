#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l1, r1, l2, r2, nt, nn, q, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2); swap(r1, r2);
        }
        nt = min(r1, r2) - max(l1, l2);
        nn = max(r1, r2) - min(l1, l2);
        if (nt <= 0) {
            a = -nt; b = nn;
        } else {
            a = 0; b = nn - nt; k -= n * nt;
        }

        // cout << a << ' ' << b << nl;

        if (k <= 0) {
            cout << 0 << nl; continue;
        }

        if (b == 0) {
            q = -1; r = k;
        } else {
            q = k / b; r = k % b;
        }
        res = 0;
        if (q == -1) {
            res += 2 * k;
        } else if (n > q) {
            res += q * (a + b);
            if (r < a && q > 0) res += 2 * r;
            else res += a + r;
        } else {
            q -= n; res += n * (a + b);
            res += 2 * (q * b + r);
        }

        cout << res << nl;
    }

    return 0;
}