#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 30010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

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
        for (i = 0; i < n; i++) {
            if (i == 0) {
                b[i] = 0; continue;
            }
            b[i] = max(b[i - 1], b[i - 1] + a[i] - a[i - 1]);
        }

        /* for (i = 0; i < n; i++) cout << b[i] << ' ';
        cout << nl; */

        if (b[n - 1] <= a[n - 1]) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}