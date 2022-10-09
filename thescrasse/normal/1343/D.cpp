#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], b, mn, mx, x, y, ps[400020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < 2 * k + 10; i++) {
            ps[i] = 0;
        }
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n / 2; i++) {
            x = a[i];
            y = a[n - i - 1];
            if (x > y) {
                swap(x, y);
            }
            mn = x + 1; mx = k + y;
            ps[mn]++; ps[mx + 1]--;
        }
        for (i = 1; i < 2 * k + 10; i++) {
            ps[i] += ps[i - 1];
        }
        for (i = 0; i < n / 2; i++) {
            x = a[i];
            y = a[n - i - 1];
            ps[x + y]++;
        }

        /* for (i = 0; i < 2 * k + 10; i++) {
            cout << ps[i] << ' ';
        }
        cout << endl; */

        res = 0;
        for (i = 0; i < 2 * k + 10; i++) {
            res = max(res, ps[i]);
        }
        res = n - res;
        cout << res << endl;
    }

    return 0;
}