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
 
double dp[2001][2001];
long long dpMod[2001][2001];
long long M = 1e9 + 7;
long long inv2 = (M + 1) / 2;
long long inv(long long b, long long p = M - 2) {
    if (p == 0) return 1;
    long long x = inv(b, p / 2);
    x = x * x % M;
    if (p % 2) x = x * b % M;
    return x;
}
long long fact[1000001], invfact[1000001], tpow[1000001], invtpow[1000001];

long long ch(int i, int j) {
    if (j > i || j < 0) return 0;
    return fact[i] * invfact[j] % M * invfact[i - j] % M;
}

int main() {
    int t; cin >> t;
    fact[0] = 1LL;
    tpow[0] = 1LL;
    for (int i = 1; i <= 1000000; i++) {
        fact[i] = fact[i - 1] * i % M;
        tpow[i] = tpow[i - 1] * 2 % M;
    }
    invtpow[1000000] = inv(tpow[1000000]);
    invfact[1000000] = inv(fact[1000000]);
    for (int i = 999999; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % M;
        invtpow[i] = invtpow[i + 1] * 2 % M;
    }
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        if (n == m) {
            long long ans = k * 1LL * n;
            ans %= M;
            if (ans < 0) ans += M;
            cout << ans << "\n";
            continue;
        }
        long long ans = 0LL;
        for (int a = 0; a <= m; a++) {
            long long num = ch(n - a - 1, n - m - 1);
            long long den = invtpow[n - a];
            num = num * den % M;
            num = num * a % M;
            ans += num;
            ans %= M;
        }
        ans *= k;
        ans %= M;
        if (ans < 0) ans += M;
        cout << ans << "\n";
    }
}