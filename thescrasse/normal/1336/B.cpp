#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n[3], m, res, check1, a, b, c, x, y, z, o;
vector<long long> w[3];

long long bs(long long s, long long v) {
    long long bsl, bsu, bsm;
    bsl = 0;
    bsu = n[v];
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        if (w[v][bsm] < s) {
            bsl = bsm + 1;
        } else {
            bsu = bsm;
        }
    }
    return bsl;
}

long long val(long long x, long long y, long long z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        for (i = 0; i < 3; i++) {
            cin >> n[i];
        }
        for (i = 0; i < 3; i++) {
            w[i].clear();
            for (j = 0; j < n[i]; j++) {
                cin >> a;
                w[i].push_back(a);
            }
            w[i].push_back((long long)2e9 + 7);
            sort(w[i].begin(), w[i].end());
        }

        res = 4e18;
        for (o = 0; o < 3; o++) {
            for (i = 0; i < n[o]; i++) {
                // cout << i << endl;
                a = i;
                x = w[o][a];
                b = bs(x, (o + 1) % 3);
                c = bs(x, (o + 2) % 3);
                if (w[(o + 1) % 3][b] == x) {
                    if (c > 0) {
                        z = w[(o + 2) % 3][c - 1];
                        res = min(res, val(x, x, z));
                    }
                    z = w[(o + 2) % 3][c];
                    res = min(res, val(x, x, z));
                }
                if (b > 0) {
                    y = w[(o + 1) % 3][b - 1];
                    z = w[(o + 2) % 3][c];
                    res = min(res, val(x, y, z));
                }
                if (c > 0) {
                    y = w[(o + 1) % 3][b];
                    z = w[(o + 2) % 3][c - 1];
                    res = min(res, val(x, y, z));
                }
            }
        }

        cout << res << endl;
        // cout << "---------" << endl;
    }

    return 0;
}