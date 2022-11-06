#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long fpow(long long a, long long n) {
    (n += mod - 1) %= mod - 1;
    (a += mod) %= mod;
    long long r = 1;
    for (; n; n >>= 1) {
        if (n & 1) (r *= a) %= mod;
        (a *= a) %= mod;
    }
    return r;
}

int main() {
    long long x, k; cin >> x >> k;
    if (x == 0) {
        cout << "0" << endl;
        return 0;
    }
    long long tk = fpow(2, k);
    x %= mod;
    (x *= tk) %= mod;
    long long inv = fpow(2, -1);
    (inv *= ((tk - 1 + mod) % mod)) %= mod;
    inv = mod - inv;
    (x += inv) %= mod;
    (x *= 2) %= mod;
    cout << x << endl;
}