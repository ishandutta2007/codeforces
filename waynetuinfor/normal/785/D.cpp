#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
long long fac[maxn], invfac[maxn];

void init();
long long fpow(int, int);
long long c(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    string s; cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) if (s[i] == ')') ++b;
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') ++a;
        if (s[i] == ')') --b;
        if (s[i] == '(') ans += c(a + b - 1, a);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

void init() {
    fac[0] = 1LL; invfac[0] = 1LL;
    for (int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % mod, invfac[i] = fpow(fac[i], mod - 2);
}

long long fpow(int a, int n) {
    long long ret = 1LL;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a, ret %= mod;
        a = (long long)a * (long long)a % mod;
    }
    return ret;
}

long long c(int n, int k) {
    return ((fac[n] * invfac[k] % mod) * invfac[n - k]) % mod;
}