#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> x; k = 0; flag[0] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i]; k += a[i];
            if (a[i] % x != 0) flag[0] = 1;
        }

        if (k % x != 0) {
            cout << n << nl;
        } else if (flag[0] == 0) {
            cout << -1 << nl;
        } else {
            res = 0;
            for (i = 0; i < n; i++) {
                if (a[i] % x != 0) {
                    res = max(res, n - i - 1);
                    break;
                }
            }
            for (i = n - 1; i >= 0; i--) {
                if (a[i] % x != 0) {
                    res = max(res, i);
                    break;
                }
            }

            cout << res << nl;
        }
    }

    return 0;
}