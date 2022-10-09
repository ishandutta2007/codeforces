#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k; k--; m = -INF;
        for (i = 0; i < n; i++) {
            cin >> a[i]; m = max(m, a[i]);
        }
        for (i = 0; i < n; i++) {
            a[i] = m - a[i];
        }

        m = -INF;
        if (k % 2 == 1) {
            for (i = 0; i < n; i++) {
                m = max(m, a[i]);
            }
            for (i = 0; i < n; i++) {
                a[i] = m - a[i];
            }
        }

        for (i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << nl;
    }

    return 0;
}