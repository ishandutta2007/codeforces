#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[40], b[40], l, r;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n); reverse(a, a + n);
        sort(b, b + n); reverse(b, b + n);
        res = 0; l = 0; r = 0;
        for (i = 0; i < n; i++) {
            if (r >= k) {
                // cout << a[l] << endl;
                res += a[l]; l++;
            } else if (a[l] >= b[r]) {
                // cout << a[l] << endl;
                res += a[l]; l++;
            } else {
                // cout << b[r] << endl;
                res += b[r]; r++;
            }
        }

        cout << res << endl;
        // cout << endl;
    }

    return 0;
}