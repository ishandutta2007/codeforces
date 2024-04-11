#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[100010], b[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        b[0] = a[0];
        for (i = 1; i < n; i++) {
            b[i] = max(b[i - 1], a[i]);
        }
        for (i = 0; i < n; i++) {
            b[i] = b[i] - a[i];
        }
        m = 0;
        for (i = 0; i < n; i++) {
            m = max(m, b[i]);
        }

        k = 1;
        res = 0;
        while (k - 1 < m) {
            k *= 2;
            res++;
        }
        cout << res << endl;
    }

    return 0;
}