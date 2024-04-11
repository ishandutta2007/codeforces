// 340B
// area massima di un quadrilatero

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, x[310], y[310], m1, m2;
vector<long long> areas;

long long crpr(long long xa, long long ya, long long xb, long long yb, long long xc, long long yc) {
    long long x1, x2, y1, y2;
    x1 = xb - xa; x2 = xc - xb; y1 = yb - ya; y2 = yc - yb;
    return x1 * y2 - x2 * y1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    res = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            areas.clear();
            for (k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                areas.push_back(crpr(x[i], y[i], x[j], y[j], x[k], y[k]));
            }
            m1 = 0;
            m2 = 0;
            for (auto u : areas) {
                m1 = min(m1, u);
                m2 = max(m2, u);
            }
            if (m1 < 0 && m2 > 0) {
                res = max(res, m2 - m1);
            }
        }
    }

    cout << fixed;
    cout << (double)res / 2;

    return 0;
}