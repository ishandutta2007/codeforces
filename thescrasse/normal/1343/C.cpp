#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], b, mn, mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        mn = (long long)-1e18;
        mx = 0;
        res = 0;
        if (a[0] < 0) {
            mn = a[0];
        } else {
            mx = a[0];
        }
        for (i = 1; i < n; i++) {
            if (a[i] * a[i - 1] > 0) {
                if (a[i] < 0) {
                    mn = max(mn, a[i]);
                } else {
                    mx = max(mx, a[i]);
                }
            } else {
                if (a[i] < 0) {
                    res += mx;
                } else {
                    res += mn;
                }
                mn = (long long)-1e18;
                mx = 0;
                if (a[i] < 0) {
                    mn = max(mn, a[i]);
                } else {
                    mx = max(mx, a[i]);
                }
            }
            //cout << i << ' ' << a[i] << ' '  << mn << ' ' << mx << ' ' << res << endl;
        }
        if (a[n - 1] < 0) {
            res += mn;
        } else {
            res += mx;
        }
        cout << res << endl;
    }

    return 0;
}