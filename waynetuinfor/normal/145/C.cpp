#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxm = 1500 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

map<int, int> ds;
int ul, cnt[maxm], f[maxn], invf[maxn], dp[maxm][maxm];
bool v[maxm][maxm];

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

void decode(int a) {
    stringstream ss; ss << a;
    string s; ss >> s;
    bool unlucky = false;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != '4' && s[i] != '7') unlucky = true;
    }
    if (unlucky) return ++ul, void();
    if (ds.find(a) != ds.end()) ++cnt[ds[a]];
    else ds[a] = ds.size(), ++cnt[ds[a]];
}

inline int C(int n, int k) { return n < k ? 0 : mul(f[n], mul(invf[k], invf[n - k])); }

int go(int n, int k) {
    if (k > n) return 0;
    if (n == 0) {
        if (k == 0) return 1;
        return 0;
    }
    if (v[n][k]) return dp[n][k];
    v[n][k] = true;
    dp[n][k] = go(n - 1, k);
    if (k > 0) dp[n][k] = add(dp[n][k], mul(go(n - 1, k - 1), cnt[n]));
    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        decode(a);
    }
    int lc = (int)ds.size(), ans = 0;
    for (int i = 0; i <= min(ul, k); ++i) {
        ans = add(ans, mul(C(ul, i), go(lc, k - i)));
    }
    cout << ans << endl;
    return 0;
}