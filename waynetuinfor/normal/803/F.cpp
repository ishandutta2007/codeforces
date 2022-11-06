#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int a[maxn], c[maxn], ans[maxn];

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= sqrt(a[i]); ++j) if (a[i] % j == 0) {
            if (j == a[i] / j) ++c[j];
            else ++c[j], ++c[a[i] / j];
        }        
    }
    for (int i = maxn - 1; i >= 2; --i) {
        ans[i] = fpow(2, c[i]);
        ans[i] = sub(ans[i], 1);
        for (int j = 2; i * j < maxn; ++j) ans[i] = sub(ans[i], ans[i * j]);
    }
    int s = 0;
    for (int i = 1; i < maxn; ++i) s = add(s, ans[i]);
    cout << sub(sub(fpow(2, n), 1), s) << endl;
    return 0;
}