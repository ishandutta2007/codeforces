#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, flag[10], a[maxn], b, cp, l;
long double ta[maxn][2], df, res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cout << fixed << setprecision(20);
    cin >> t;
    while (t--) {
        cin >> n >> l; a[0] = 0; a[n + 1] = l;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        n += 2;

        ta[0][0] = 0; ta[n - 1][1] = 0;
        for (i = 1; i < n; i++) {
            ta[i][0] = ta[i - 1][0] + (long double)(a[i] - a[i - 1]) / i;
        }
        for (i = n - 2; i >= 0; i--) {
            ta[i][1] = ta[i + 1][1] + (long double)(a[i + 1] - a[i]) / (n - i - 1);
        }

        for (i = 0; i < n; i++) {
            if (ta[i][0] > ta[i][1]) {
                cp = i - 1; break;
            }
        }

        /* for (i = 0; i < n; i++) {
            cout << ta[i][0] << ' ' << ta[i][1] << nl;
        } */
        df = a[cp + 1] - a[cp]; res = ta[cp][0];
        // cout << df << nl;
        if (ta[cp][0] < ta[cp + 1][1]) {
            df -= (cp + 1) * (ta[cp + 1][1] - ta[cp][0]);
            res = ta[cp + 1][1];
        } else {
            df -= (n - cp - 1) * (ta[cp][0] - ta[cp + 1][1]);
        }
        res += df / n;
        cout << res << nl;
    }

    return 0;
}