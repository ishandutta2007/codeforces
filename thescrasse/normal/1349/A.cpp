#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[100010], b, v, er[200010], nw, m1[200010], m2[200010], upd[200010], q[200010];
pair<ll, ll> f[200010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i <= 200000; i++) {
        er[i] = i;
    }

    for (i = 2; i <= 200000; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j <= 200000; j += i) {
                er[j] = i;
            }
        }
    }

    for (i = 2; i <= 200000; i++) {
        m1[i] = INF; m2[i] = INF; upd[i] = -1; q[i] = 0; f[i] = {-1, -1};
    }

    for (i = 0; i < n; i++) {
        k = a[i];
        while (k != 1) {
            // cout << k << endl << flush;
            nw = er[k];
            if (f[nw].second != i) {
                f[nw] = {1, i};
            } else {
                f[nw].first++;
            }
            k /= nw;
        }

        k = a[i];
        while (k != 1) {
            nw = er[k];
            if (upd[nw] != i) {
                upd[nw] = i;
                v = f[nw].first;
                if (v < m1[nw]) {
                    m2[nw] = m1[nw]; m1[nw] = v;
                } else if (v < m2[nw]) {
                    m2[nw] = v;
                }
                q[nw]++;
            }
            k /= nw;
        }
    }

    /* for (i = 2; i <= 100; i++) {
        cout << q[i] << ' ' << m1[i] << ' ' << m2[i] << ' ' << endl << flush;
    } */

    res = 1;
    for (i = 2; i <= 200000; i++) {
        if (n - q[i] == 0) {
            for (j = 0; j < m2[i]; j++) {
                res *= i;
            }
        } else if (n - q[i] == 1) {
            for (j = 0; j < m1[i]; j++) {
                res *= i;
            }
        }
    }

    cout << res;

    return 0;
}