#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn], r[maxn];

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
            cin >> b[i];
        }
        for (i = 0; i < n; i++) {
            cin >> c[i];
        }

        r[0] = a[0];
        for (i = 1; i < n - 1; i++) {
            if (a[i] != r[i - 1]) {
                r[i] = a[i]; continue;
            }
            if (b[i] != r[i - 1]) {
                r[i] = b[i]; continue;
            }
            if (c[i] != r[i - 1]) {
                r[i] = c[i]; continue;
            }
        }

        for (i = n - 1; i < n; i++) {
            if (a[i] != r[i - 1] && a[i] != r[0]) {
                r[i] = a[i]; continue;
            }
            if (b[i] != r[i - 1] && b[i] != r[0]) {
                r[i] = b[i]; continue;
            }
            if (c[i] != r[i - 1] && c[i] != r[0]) {
                r[i] = c[i]; continue;
            }
        }

        for (i = 0; i < n; i++) cout << r[i] << ' ';
        cout << nl;
    }

    return 0;
}