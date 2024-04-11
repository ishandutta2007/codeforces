#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[100010], b[100010], f[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (i = 0; i < 3; i++) {
            f[i] = 0;
        }
        check1 = 1;
        for (i = 0; i < n; i++) {
            if (a[i] == b[i]) {
            }
            if (a[i] < b[i]) {
                if (f[2] == 0) {
                    check1 = 0;
                }
            }
            if (a[i] > b[i]) {
                if (f[0] == 0) {
                    check1 = 0;
                }
            }
            f[a[i] + 1] = 1;
        }
        if (check1 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}