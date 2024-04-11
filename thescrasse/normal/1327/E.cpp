#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, mod;

long long fstx(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        long long r = fstx(a, b / 2);
        return (r * r) % mod;
    } else {
        long long r = fstx(a, b - 1);
        return (r * a) % mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 998244353;

    cin >> n;
    for (i = 1; i <= n; i++) {
        if (i == n) {
            res = 10;
        } else if (i == n - 1) {
            res = 180;
        } else {
            res = (2 * 9 * fstx(10, n - i)) % mod;
            res = (res + ((n - i - 1) * 81 * fstx(10, n - i - 1)) % mod) % mod;
        }
        cout << res << ' ';
    }

    return 0;
}