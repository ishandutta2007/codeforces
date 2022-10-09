#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], b, w;
array<ll, 2> a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> w;
        for (i = 0; i < n; i++) {
            cin >> b; a[i] = {b, i + 1};
        }

        sort(a, a + n); k = 0; flag[0] = 0;
        for (i = 0; i < n; i++) {
            k += a[i][0];
            if (k > w) break;
            if (k >= (w + 1) / 2) {
                cout << i + 1 << nl;
                for (j = 0; j <= i; j++) cout << a[j][1] << ' ';
                cout << nl;
                flag[0] = 1; break;
            }
        }

        if (flag[0] == 1) continue;

        if (k < (w + 1) / 2) {
            cout << -1 << nl; continue;
        }

        if (k > w) {
            if (a[i][0] > w) {
                cout << -1 << nl; continue;
            } else {
                cout << 1 << nl;
                cout << a[i][1] << nl;
            }
        } else {
            cout << n << nl;
            for (j = 0; j < n; j++) cout << a[j][1] << ' ';
            cout << nl;
        }
    }

    return 0;
}