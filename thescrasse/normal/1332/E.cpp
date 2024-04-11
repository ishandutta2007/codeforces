#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, l, r, mod, dimr, dimm, signr, signm;

long long fexp(long long a, long long b) {
    long long v;
    if (b == 0) {
        return 1;
    } else {
        if (b % 2 == 0) {
            v = (fexp(a, b / 2)) % mod;
            return (v * v) % mod;
        } else {
            v = (fexp(a, b - 1)) % mod;
            return (v * a) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m >> l >> r;
    mod = 998244353;

    if (n == 1 && m == 1) {
        cout << r - l + 1;
        return 0;
    }

    dimr = r - l + 1;
    if (dimr % 2 == 0) {
        signr = 0;
    } else {
        signr = 69420;
    }

    dimm = n * m;
    if (dimm % 2 == 0) {
        signm = 0;
    } else {
        signm = 69420;
    }

    if (signr == 0) {
        if (signm == 0) {
            res = (fexp(dimr, dimm) * fexp(2, mod - 2)) % mod;
        } else {
            res = fexp(dimr, dimm) % mod;
        }
    } else {
        if (signm == 0) {
            res = (((fexp(dimr, dimm) + 1) % mod) * fexp(2, mod - 2)) % mod;
        } else {
            res = fexp(dimr, dimm) % mod;
        }
    }

    cout << res;

    return 0;
}