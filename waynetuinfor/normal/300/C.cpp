#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, maxn = 1e6 + 10;
int f[maxn], inv[maxn];

inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}
int main() {
    int a, b, n; cin >> a >> b >> n;
    f[0] = 1, inv[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = mul(f[i - 1], i), inv[i] = fpow(f[i], mod - 2);
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int j = n - i;
        int now = a * i + b * j;
        bool ok = true;
        while (now) {
            if (now % 10 != a && now % 10 != b) ok = false;
            now /= 10;
        }
        if (ok) ans = add(ans, mul(f[n], mul(inv[i], inv[j])));
    } 
    cout << ans << endl;
    return 0;
}