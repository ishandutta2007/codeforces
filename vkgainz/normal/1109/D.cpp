#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
long long fac[1000001], inv[1000001];
long long npow[1000001], mpow[1000001];
long long MOD = 1e9 + 7;

long long power(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = power(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

long long choose(int x, int y) {
    if (y < 0 || y > x) return 0LL;
    return fac[x] * inv[x - y] % MOD * inv[y] % MOD;
}

int main() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    npow[0] = 1LL, mpow[0] = 1LL;
    fac[0] = 1LL, inv[0] = 1LL;
    for (int i = 1; i <= 1000000; i++) {
        npow[i] = npow[i - 1] * n % MOD;
        mpow[i] = mpow[i - 1] * m % MOD;
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = inv[i - 1] * power(i) % MOD;
    }
    long long ans = choose(m - 1, n - 2) * fac[n - 2] % MOD;
    for (int z = 0; z < n - 2; z++) {
        long long L, R, ch;
        L = (z + 2) * 1LL * npow[n - z - 3] % MOD;
        R = mpow[n - z - 2];
        ch = choose(m - 1, z) * fac[z] % MOD * choose(n - 2, z) % MOD;
        ans += L * R % MOD * ch % MOD;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}