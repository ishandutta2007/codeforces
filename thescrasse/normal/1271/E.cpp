// 1271E
// sequenza con x / 2, x - 1

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, bsl, bsu, bsm, bsd, p2[62], c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k;

    for (i = 0; i < 62; i++) {
        p2[i] = (long long)1 << i;
        // cout << p2[i] << endl;
    }

    bsl = 0;
    bsu = n / 2 + 1;
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        bsd = 2 * bsm + 1;
        // cout << bsl << ' ' << bsu << ' ' << bsd << endl;
        for (i = 0; i < 62; i++) {
            if (n < (bsd * p2[i])) {
                break;
            }
        }
        i--;
        // cout << i << endl;
        c = p2[i] - 1 + min(p2[i], n - (bsd * p2[i]) + 1);
        // cout << c << endl;
        if (c >= k) {
            bsl = bsm + 1;
        } else {
            bsu = bsm;
        }
    }
    res = 2 * bsl - 1;

    bsl = 0;
    bsu = n / 2 + 1;
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        bsd = 2 * bsm;
        // cout << bsl << ' ' << bsu << ' ' << bsd << endl;
        for (i = 0; i < 62; i++) {
            if (n < (bsd * p2[i])) {
                break;
            }
        }
        i--;
        c = p2[i + 1] - 2 + min(p2[i + 1], n - (bsd * p2[i]) + 1);
        // cout << c << endl;
        if (c >= k) {
            bsl = bsm + 1;
        } else {
            bsu = bsm;
        }
    }
    res = max(res, 2 * bsl - 2);

    cout << res;

    return 0;
}