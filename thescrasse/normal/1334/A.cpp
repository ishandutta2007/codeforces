#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, p[110], c[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        p[0] = 0; c[0] = 0;
        for (i = 1; i <= n; i++) {
            cin >> p[i] >> c[i];
        }

        check1 = 1;
        for (i = 0; i < n; i++) {
            if (p[i] > p[i + 1] || c[i] > c[i + 1] || (c[i + 1] - c[i]) > (p[i + 1] - p[i])) {
                check1 = 0;
            }
        }

        if (check1 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}