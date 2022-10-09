#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn], x;

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

        sort(a, a + n);

        b[0] = a[n - 1]; c[0] = b[0]; a[n - 1] = -1;
        for (i = 1; i < n; i++) {
            m = 0; k = 0;
            for (j = 0; j < n; j++) {
                if (a[j] == -1) continue;
                x = __gcd(c[i - 1], a[j]);
                if (x > m) {
                    m = x; k = j;
                }
            }

            b[i] = a[k]; c[i] = m; a[k] = -1;
        }

        for (i = 0; i < n; i++) cout << b[i] << ' ';
        cout << nl;
    }

    return 0;
}