#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, x, m, res, check1, a, b, l, r, p, bsl, bsm, bsu, q, d;

long long binom(long long a) {
    return (a * (a + 1)) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        check1 = 0;
        if (l == r && r == n * (n - 1) + 1) {
            cout << 1 << endl;
            continue;
        }
        if (r == n * (n - 1) + 1) {
            r--;
            check1 = 1;
        }
        d = r - l + 1;
        l++;
        p = l % 2;
        l /= 2;
        l = ((n * (n - 1)) / 2) - l + 1;
        //cout << "ok" << endl;
        bsl = -1;
        bsu = (long long)1e7;
        while (bsl != bsu) {
            //cout << bsl << ' ' << bsu << endl;
            bsm = (bsl + bsu) / 2;
            if (binom(bsm) >= l) {
                bsu = bsm;
            } else {
                bsl = bsm + 1;
            }
        }
        k = n - bsl;
        q = k + binom(bsl) - l + 1;
        //cout << k << ' ' << q << endl << endl;
        if (p == 0) {
            cout << k << ' ';
            d--;
        }
        if (d > 0) {
            cout << q << ' ';
            d--;
            q++;
        }
        p = 0;
        while (d > 0) {
            if (q > n) {
                k++;
                q = k + 1;
            }
            if (p == 0) {
                cout << k << ' ';
            } else {
                cout << q << ' ';
                q++;
            }
            p = (p + 1) % 2;
            d--;
        }
        if (check1 == 1) {
            cout << 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}