#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, x, m, res, check1, a[100010], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);
        reverse(a, a + n);
        k = 0;
        res = 0;
        for (i = 0; i < n; i++) {
            k += a[i];
            if (k >= x * (i + 1)) {
                res = i + 1;
            } else {
                break;
            }
        }

        cout << res << endl;
    }

    return 0;
}