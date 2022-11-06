#include <bits/stdc++.h>
using namespace std;

const int maxn = 2097152;
const int mod = 998244353;
const int root = 3;
int d[11], dp[maxn];

template <long long mod, long long root>
struct NTT {
    vector<long long> omega;
    NTT() {
        omega.resize(maxn + 1);
        long long x = fpow(root, (mod - 1) / maxn);
        omega[0] = 1ll;
        for (int i = 1; i <= maxn; ++i)
            omega[i] = omega[i - 1] * x % mod;
    }
    long long fpow(long long a, long long n) {
        (n += mod - 1) %= mod - 1;
        long long r = 1;
        for (; n; n >>= 1) {
            if (n & 1) (r *= a) %= mod;
            (a *= a) %= mod;
        }
        return r;
    }
    void bitrev(vector<long long> &v, int n) {
        int z = __builtin_ctz(n) - 1;
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j <= z; ++j) x ^= (i >> j & 1) << (z - j);
            if (x > i) swap(v[x], v[i]);
        }
    }
    void ntt(vector<long long> &v, int n) {
        bitrev(v, n);
        for (int s = 2; s <= n; s <<= 1) {
            int z = s >> 1;
            for (int i = 0; i < n; i += s) {
                for (int k = 0; k < z; ++k) {
                    long long x = v[i + k + z] * omega[maxn / s * k] % mod; 
                    v[i + k + z] = (v[i + k] + mod - x) % mod;
                    (v[i + k] += x) %= mod; 
                }
            }
        }
    }
    void intt(vector<long long> &v, int n) {
        ntt(v, n);
        for (int i = 1; i < n / 2; ++i) swap(v[i], v[n - i]);
        long long inv = fpow(n, -1);
        for (int i = 0; i < n; ++i) (v[i] *= inv) %= mod;
    }
    vector<long long> operator()(vector<long long> a, vector<long long> b) {
        int sz = 1;
        while (sz < a.size() + b.size() - 1) sz <<= 1;
        while (a.size() < sz) a.push_back(0);
        while (b.size() < sz) b.push_back(0);
        ntt(a, sz), ntt(b, sz);
        vector<long long> c(sz);
        for (int i = 0; i < sz; ++i) c[i] = a[i] * b[i] % mod;
        intt(c, sz);
        while (c.size() && c.back() == 0) c.pop_back();
        return c;
    }
};

NTT<mod, root> conv;

vector<long long> fpow(const vector<long long> &v, int n) {
    if (n == 1) return v;
    vector<long long> res = fpow(v, n / 2);
    res = conv(res, res);
    if (n & 1) res = conv(res, v);
    return res;
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<long long> v(10, 0);
    for (int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        v[x] = 1;
    }       
    v = fpow(v, n / 2);
    int ans = 0;
    for (int i = 0; i < (int)v.size(); ++i) ans = (ans + 1ll * v[i] * v[i] % mod) % mod;
    printf("%d\n", ans);
    return 0;
}