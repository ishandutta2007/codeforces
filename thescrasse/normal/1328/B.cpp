#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, bsl, bsm, bsu, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n >> k;
        bsl = 0;
        bsu = n;
        while (bsl != bsu) {
            // cout << bsl << ' ' << bsu << endl;
            bsm = (bsl + bsu) / 2;
            if ((bsm * (bsm - 1)) / 2 >= k) {
                bsu = bsm;
            } else {
                bsl = bsm + 1;
            }
        }
        d = k - ((bsl - 1) * (bsl - 2)) / 2;
        // cout << bsl << ' ' << d << endl;
        for (i = 0; i < n; i++) {
            if (n - i == d || n - i == bsl) {
                cout << 'b';
            } else {
                cout << 'a';
            }
        }
        cout << endl;
    }

    return 0;
}