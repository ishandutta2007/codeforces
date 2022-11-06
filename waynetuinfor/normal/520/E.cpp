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
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = mul(f[i - 1], i);
        invf[i] = fpow(f[i], mod - 2);
    }
}

inline int C(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(f[n], mul(invf[k], invf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    init();
    int m = 0, t = 1;
    string s; cin >> s;
    int ans = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans = add(ans, mul(s[i] - '0', m));
        ans = add(ans, mul(s[i] - '0', mul(C(i, k), t)));
        m = add(m, mul(C(n - j - 2, k - 1), t));
        t = mul(t, 10);
        ++j;
    }
    cout << ans << endl;
    return 0;
}