#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, check2, a[200010], b, bsl, bsm, bsu, d, cn;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   // ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = a[0];
        check1 = 0;
        check2 = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                check2 = 1;
            } else {
                check1 = 1;
            }
        }
        if (check1 == 1 && check2 == 1) {
            cout << 2 << endl;
            check1 = ((n + 1) % 2);
            cn = 1;
            cout << 1 << ' ';
            for (i = 1; i < n; i++) {
                if (a[i] != a[i - 1]) {
                    cn++;
                } else {
                    if (check1 == 0) {
                        check1 = 1;
                    } else {
                        cn++;
                    }
                }
                if (cn == 3) {
                    cn = 1;
                }
                cout << cn << ' ';
            }
            cout << endl;
        } else if (check1 == 1) {
            if (n % 2 == 0) {
                cout << 2 << endl;
                for (i = 0; i < n; i++) {
                    cout << (i % 2) + 1 << ' ';
                }
                cout << endl;
            } else {
                cout << 3 << endl;
                for (i = 0; i < n - 1; i++) {
                    cout << (i % 2) + 1 << ' ';
                }
                cout << 3 << ' ';
                cout << endl;
            }
        } else {
            cout << 1 << endl;
            for (i = 0; i < n; i++) {
                cout << 1 << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}