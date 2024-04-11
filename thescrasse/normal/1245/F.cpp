// 1245F
// Daniel and Spring Cleaning

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l, r;

ll solve(ll x, ll y) {
    res = 0;
    if (x < 0 || y < 0) return 0;
    for (i = 30; i >= -1; i--) {
        if (i != -1 && !((x >> i) & 1)) continue;
        for (j = 30; j >= -1; j--) {
            if (j != -1 && !((y >> j) & 1)) continue;
            m = 1;
            for (k = 30; k >= 0; k--) {
                a = (x >> k) & 1; b = (y >> k) & 1;
                if (k > i && k > j && a + b == 2) m = 0;
                else if (k > i && k > j) m *= 1;
                else if (k < i && k < j) m *= 3;
                else if (k >= i && k >= j) m *= 1;
                else if (k == i || (k > i && a == 0)) m *= 2;
                else if (k == j || (k > j && b == 0)) m *= 2;
            }
            res += m;
            // cout << "i, j, m = " << i << ' ' << j << ' ' << m << nl;
        }
    }

    // cout << x << ' ' << y << ' ' << res << nl;
    return res;
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
        cin >> l >> r;
        res = solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1);
        cout << res << nl;
    }

    return 0;
}