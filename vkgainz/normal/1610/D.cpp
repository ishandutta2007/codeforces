#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <chrono>
 
using namespace std;
 
long long MOD = 1e9 + 7;
vector<long long> f, inv;
vector<long long> tpow;

long long inver(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inver(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

long long choose(int n, int k) {
    if (k > n || k < 0) return 0LL;
    return f[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    f.resize(n + 1), inv.resize(n + 1);
    tpow.resize(n + 1);
    f[0] = 1, inv[0] = 1;
    tpow[0] = 1LL;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1]) * i % MOD;
        inv[i] = inver(f[i]);
        tpow[i] = tpow[i - 1] * 2 % MOD;
    }
    vector<int> num(30);
    for (int i = 0; i < n; i++) {
        int x = 0;
        while (a[i] % 2 == 0) {
            ++x;
            a[i] /= 2;
        }
        ++num[x];
    }
    long long ans = 0LL;
    int left = n;
    for (int j = 0; j < 30; j++) {
        left -= num[j];
        if (j == 0) {
            ans += tpow[n] - tpow[left];
        } else {
            for (int ch = 2; ch <= num[j]; ch += 2) {
                ans += choose(num[j], ch) * 1LL * tpow[left] % MOD;
                ans %= MOD;
            }
        }
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}