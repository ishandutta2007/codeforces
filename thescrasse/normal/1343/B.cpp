#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, p[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        res = 0;
        for (i = 1; i <= n / 2; i++) {
            cout << 2 * i << ' ';
            res += (2 * i);
        }
        for (i = 1; i <= n / 2 - 1; i++) {
            cout << 2 * i - 1 << ' ';
            res -= (2 * i - 1);
        }
        cout << res << endl;
    }

    return 0;
}