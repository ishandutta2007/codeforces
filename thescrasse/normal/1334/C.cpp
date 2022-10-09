#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, x, m, res, check1, a[300010], b[300010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        a[n] = a[0];

        for (i = 0; i < n; i++) {
            b[i] = min(b[i], a[i + 1]);
        }
        b[n] = b[0];

        sort(b, b + n);
        res = 0;
        for (i = 0; i < n; i++) {
            res += a[i];
            if (i != 0) {
                res -= b[i];
            }
        }

        cout << res << endl;
    }

    return 0;
}