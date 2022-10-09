#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

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
        m = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i]; m += a[i];
        }

        sort(a, a + n);
        if (m == 0) {
            cout << "NO" << nl; continue;
        }

        if (m > 0) reverse(a, a + n);

        cout << "YES" << nl;
        for (i = 0; i < n; i++) cout << a[i] << ' ';
        cout << nl;
    }

    return 0;
}