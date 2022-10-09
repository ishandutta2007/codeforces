#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, d, w, x, q, r;

ll bnm(ll x) {
    if (x <= 1) return 0;
    return (x * (x - 1)) / 2;
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
        cin >> m >> d >> w;
        if (d == 1) {
            cout << 0 << nl; continue;
        }
        w /= __gcd(w, d - 1);
        m = min(m, d);

        q = m / w; r = m % w;
        res = 0;
        res += r * bnm(q + 1);
        res += (w - r) * bnm(q);

        cout << res << nl;
    }

    return 0;
}