#include <iostream>

int main() {
    long long n, m;
    std::cin >> n >> m;
    const long long MOD = 1e9 + 7;
    long long ans = 0;
    if(m > n) {
        ans = (m - n) % MOD * (n % MOD) % MOD;
        m = n;
    }
    for(long long l = 1, r; l <= m; l = r + 1) {
        r = n / (n / l);
        r = std::min(r, m);
        // n / i has the same value for l <= i <= r
        // ans += (n * (r - l + 1)) - (l + l + 1 + l + 2 + ... + r) * (n / i);
        ans += (n % MOD * ((r - l + 1) % MOD)) - (((r + l) % MOD) * ((r - l + 1) % MOD) % MOD * ((MOD + 1) / 2) % MOD) % MOD * (n / l % MOD);
        ans = (ans % MOD + MOD) % MOD;
    }
    std::cout << ans << '\n';
}