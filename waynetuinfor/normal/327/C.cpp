#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;

long long fpow(long long a, long long n) {
    long long ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    bool ok = false;
    int n = (int)s.length();
    for (int i = 0; i < s.length(); ++i) if (s[i] == '0' || s[i] == '5') ok = true; 
    if (!ok) return cout << "0" << endl, 0;
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) if (s[i] == '0' || s[i] == '5') {
        long long p = fpow(2, n) - 1; if (p < 0) p += mod;
        long long inv = fpow(p, mod - 2);
        p = fpow(2, (long long)n * (long long)k) - 1; if (p < 0) p += mod;
        ans = (ans + (fpow(2, i) * p % mod * inv % mod)) % mod;
    }
    cout << ans << endl;
    return 0;
}