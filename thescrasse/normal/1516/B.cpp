#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

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
        cin >> n; k = 0; x = 0; m = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; k ^= a[i];
        }

        if (k == 0) {
            cout << "YES" << nl; continue;
        }

        for (i = 1; i <= n; i++) {
            x ^= a[i];
            if (x == k) {
                x = 0; m++;
            }
        }

        if (m >= 3) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}