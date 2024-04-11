#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001000, mod = 1e9 + 7;
int f[maxn], invf[maxn], t[maxn], mindiv[maxn];
bool v[maxn];
vector<int> pr;

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
    f[0] = invf[0] = t[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = mul(f[i - 1], i);
        t[i] = mul(t[i - 1], 2);
    }
    invf[maxn - 1] = fpow(f[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; --i) invf[i] = mul(invf[i + 1], i + 1);
}

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), mindiv[i] = i;
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            mindiv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        } 
    }
}

inline int C(int n, int k) { return (n < k || k < 0 ) ? 0 : mul(f[n], mul(invf[n - k], invf[k])); }

int main() {
    sieve(); init();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q; while (q--) {
        int x, y; cin >> x >> y;
        unordered_map<int, int> divs; 
        while (x > 1) {
            ++divs[mindiv[x]];
            x /= mindiv[x];
        }
        int ans = 1;
        for (auto it = divs.begin(); it != divs.end(); ++it) ans = mul(ans, C(y + it->second - 1, it->second));
        ans = mul(ans, t[y - 1]);
        cout << ans << '\n';
    }
    return 0;
}