#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int f[maxn], invf[maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

void init() {
    f[0] = 1; invf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = mul(f[i - 1], i);
        invf[i] = fpow(f[i], mod - 2);
    }
}

int c(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return mul(f[n], mul(invf[k], invf[n - k]));
}

int main() {
    init();
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = add(ans, mul(c(n, i), c(n - 1, n - i)));
    }
    ans = mul(ans, 2);
    ans = sub(ans, n);
    cout << ans << endl;
    return 0;
}