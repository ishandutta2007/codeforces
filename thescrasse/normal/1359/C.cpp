#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, v1, v2, v3, bsl, bsu, bsm;
long double h, c, x, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> v1 >> v2 >> v3;
        h = v1; c = v2; x = v3;
        bsl = 0; bsu = (ll)1e11;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            // cout << h * (bsm + 1) + c * bsm << ' ' << x * (2 * bsm + 1) << endl;
            if (h * (bsm + 1) + c * bsm <= x * (2 * bsm + 1)) {
                bsu = bsm;
            } else {
                bsl = bsm + 1;
            }
        }
        // cout << bsl << endl;
        // r = abs((h * (bsl + 1) + c * bsl) / (2 * bsl + 1) - x);
        res = 2 * bsl + 1;
        // cout << r << endl;
        if (bsl > 0) {
            if (abs(h * (bsl + 1) + c * bsl - x * (2 * bsl + 1)) * (2 * bsl - 1) >= abs(h * bsl + c * (bsl - 1) - x * (2 * bsl - 1)) * (2 * bsl + 1)) res = 2 * bsl - 1;
        }

        if (v1 + v2 >= 2 * v3) res = 2;

        cout << res << endl;
    }

    return 0;
}