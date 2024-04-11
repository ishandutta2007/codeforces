#include <bits/stdc++.h>
using namespace std;

const int maxv = 32000, maxn = 500 + 10, mod = 1e9 + 7, maxf = 1e5 + 10;
vector<int> pr;
map<int, int> fac;
int f[maxf], invf[maxf];

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
    for (int i = 1; i < maxf; ++i) {
        f[i] = mul(f[i - 1], i);
        invf[i] = fpow(f[i], mod - 2);
    }
}

void sieve() {
    bitset<maxv> v;
    for (int i = 2; i < maxv; ++i) {
        if (!v[i]) pr.push_back(i);
        for (size_t j = 0; i * pr[j] < maxv; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
}

void decomp(int a) {
    size_t p = 0;
    while (a > 1 && p < pr.size()) {
        int c = 0;
        while (a % pr[p] == 0) a /= pr[p], ++c;
        if (c) fac[pr[p]] += c;
        ++p;
    }
    if (a > 1) ++fac[a];
}

inline int c(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(f[n], mul(invf[k], invf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init(); sieve();
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        decomp(a);
    }
    int ans = 1;
    for (auto it = fac.begin(); it != fac.end(); ++it) ans = mul(ans, c(n + it->second - 1, it->second));
    cout << ans << endl;
    return 0;
}