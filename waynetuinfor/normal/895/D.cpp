#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int f[maxn], inv[maxn], c[26];

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    string ta = a, tb = b;
    bool eq = false;
    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());
    if (ta == tb) eq = true;
    f[0] = 1; inv[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = mul(f[i - 1], i), inv[i] = fpow(f[i], mod - 2);
    int n = a.size();
    a = '.' + a; b = '.' + b;
    int ans = 0;
    for (int i = 1; i <= n; ++i) ++c[a[i] - 'a'];
    for (int i = 0; i < n; ++i) {
        if (i) --c[a[i] - 'a'];
        int m = f[n - i - 1];
        for (int j = 0; j < 26; ++j) m = mul(m, inv[c[j]]);
        for (int j = a[i + 1] - 'a' + 1; j < 26; ++j) {
            int h = c[j];
            if (h == 0) continue;
            ans = add(ans, mul(m, mul(inv[h - 1], f[h])));
        }
    }
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) ++c[a[i] - 'a'];
    int ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i) {
            if (c[b[i] - 'a']) --c[b[i] - 'a'];
            else break;
        }
        int m = f[n - i - 1];
        for (int j = 0; j < 26; ++j) m = mul(m, inv[c[j]]);
        for (int j = b[i + 1] - 'a' + 1; j < 26; ++j) {
            if (c[j] == 0) continue;
            ans2 = add(ans2, mul(m, mul(inv[c[j] - 1], f[c[j]])));
        }
    }
    if (eq) ans = sub(ans, 1);
    cout << sub(ans, ans2) << endl;
    return 0;
}