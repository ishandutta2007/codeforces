#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p, x;

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
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        m = -INF;
        for (i = 0; i < n; i++) {
            if (a[i] > m) {
                m = a[i]; p = i;
            }
        }

        for (i = 0; i < n; i++) {
            if (a[i] != a[p]) continue;
            if (i != 0 && a[i] > a[i - 1]) {
                x = i; break;
            }
            if (i != n - 1 && a[i] > a[i + 1]) {
                x = i; break;
            }
        }

        sort(a, a + n);

        if (a[0] == a[n - 1]) {
            cout << -1 << nl;
        } else {
            cout << x + 1 << nl;
        }
    }

    return 0;
}