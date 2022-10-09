#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], sm[maxn];

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
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[n + 1] = 0; a[n + 2] = 0; n += 2;

        for (i = 1; i <= n; i++) {
            b[i] = a[i] - b[i - 1];
        }

        for (i = n + 2; i >= 1; i--) {
            if (i > n) sm[i] = INF;
            else sm[i] = min(b[i], sm[i + 2]);
        }

        /* for (i = 1; i <= n; i++) {
            cout << b[i] << ' ';
        }
        cout << nl;

        for (i = 1; i <= n; i++) {
            cout << sm[i] << ' ';
        }
        cout << nl; */

        flag[0] = 0;
        for (i = 2; i <= n; i++) {
            if (b[i - 2] < 0) break;
            m = a[i - 1] - a[i]; k = 2 * m;
            if ((n + i) % 2) k *= -1;
            if (b[n] + k != 0) continue;
            if (b[i - 1] - m < 0) continue;
            if (sm[i] + 2 * m < 0) continue;
            if (i < n && sm[i + 1] - 2 * m < 0) continue;
            flag[0] = 1; cout << "YES" << nl; break;
        }

        if (flag[0] == 0) cout << "NO" << nl;
    }

    return 0;
}