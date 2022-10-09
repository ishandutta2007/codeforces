#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> u >> v;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        m = 0;
        for (i = 1; i < n; i++) {
            m = max(m, abs(a[i] - a[i + 1]));
        }

        if (m == 0) {
            cout << min(u + v, 2 * v) << nl;
        } else if (m == 1) {
            cout << min(u, v) << nl;
        } else {
            cout << 0 << nl;
        }
    }

    return 0;
}