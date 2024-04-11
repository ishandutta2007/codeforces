#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inv3 = 333333336, inv2 = 500000004;
long long a[maxn];

long long fpow(long long a, long long n) {
    long long ret = 1LL;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bool odd = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) odd = false;
    }
    long long p = 2;
    for (int i = 0; i < n; ++i) {
        p = fpow(p, a[i]);
    }
    long long q = p * inv2 % mod;
    if (odd) {
        p = (p - 2) % mod;
        if (p < 0) p += mod;
        p = p * inv3 % mod;
        p = p * inv2 % mod;
    } else {
        p = (p + 2) % mod;
        p = p * inv3 % mod;
        p = p * inv2 % mod;
    }
    cout << p << "/" << q << endl;
    return 0;
}