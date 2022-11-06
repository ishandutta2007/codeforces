#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
int f[maxn], invf[maxn];
bool v[maxn], p[maxn];
vector<int> pr;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), p[i] = true;
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
}

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

inline int c(int n, int k) { return n < k || n < 0 || k < 0 ? 0 : mul(f[n], mul(invf[k], invf[n - k])); }
inline int h(int n, int k) { return c(n + k - 1, k); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve(); init();
    int q; cin >> q; while (q--) {
        int n, f; cin >> n >> f;
        int tn = n, ans = h(f, n - f);
        size_t ptr = 0;
        vector<int> di;
        while (tn > 1) {
            if (tn % pr[ptr] == 0) di.push_back(pr[ptr]);
            while (tn % pr[ptr] == 0) tn /= pr[ptr];
            ++ptr;
        }
        int sz = di.size();
        for (int m = 1; m < (1 << sz); ++m) {
            int d = 1;
            for (size_t i = 0; i < di.size(); ++i) {
                if ((1 << i) & m) d *= di[i];
            }
            int c = h(f, n / d - f);
            if (__builtin_popcount(m) & 1) ans = sub(ans, c);
            else ans = add(ans, c);
        }
        cout << ans << endl;
    }
    return 0;
}