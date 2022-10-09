// 1207F
// query con modifica elemento e somma posizioni y mod x

//#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

int i, i1, j, k, k1, t, n, m, res, check1, a[500010], b, r[710][710], x, y, q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> q;
    for (i = 1; i <= 500000; i++) {
        a[i] = 0;
    }
    for (i = 1; i <= 700; i++) {
        for (j = 0; j <= 700; j++) {
            r[i][j] = 0;
        }
    }
    while (q--) {
        cin >> t >> x >> y;

        if (t == 1) {
            a[x] += y;
            for (i = 1; i <= 700; i++) {
                k = x % i;
                r[i][k] += y;
            }
        }

        if (t == 2) {
            if (x <= 700) {
                cout << r[x][y] << endl;
            } else {
                res = 0;
                for (i = y; i <= 500000; i += x) {
                    res += a[i];
                }
                cout << res << endl;
            }
        }
    }

    return 0;
}