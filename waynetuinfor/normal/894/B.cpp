#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, long long n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    long long n, m; int k; cin >> n >> m >> k;
    if ((n + m) % 2 == 1 && k == -1) return cout << "0" << endl, 0;
    cout << fpow(fpow(2, n - 1), m - 1) << endl;
    return 0;
}