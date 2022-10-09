#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, d, mod;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> d >> mod;
        res = 1;
        k = 1;
        while (2 * k - 1 <= d) {
            res = (res * (k + 1)) % mod;
            k *= 2;
        }

        k /= 2;
        res = (res * (d - (2 * k - 1) + 1)) % mod;
        res = (res + mod - 1) % mod;

        cout << res << endl;
    }

    return 0;
}