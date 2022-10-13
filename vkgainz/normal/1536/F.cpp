#include <bits/stdc++.h>
using namespace std;

vector<int64_t> fact, invfact;
int64_t MOD = 1e9 + 7;

int64_t inv(int64_t b, int p = MOD - 2) {
    if(p == 0) return 1;
    int64_t x = inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

int64_t choose(int a, int b) {
    if(b > a || a < 0 || b < 0) return 0;
    return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
}

int64_t f(int n, int k) {
    return (choose(n - k, k) + choose(n - k - 1, k - 1)) % MOD;
}

void solve_odd(int n) {
    int64_t ans = 0;
    for(int k = 1; k <= n; k += 2) {
        int64_t add = (fact[n - k] * f(n, k)) % MOD;
        add *= 2;
        add %= MOD;
        ans += add;
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans;
}

void solve_even(int n) {
    int64_t ans = 0;
    for(int k = 0; k <= n; k += 2) {
        int64_t add = (fact[n - k] * f(n, k)) % MOD;
        add *= 2;
        add %= MOD;
        ans += add;
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans;
}

int main() {
    fact.resize(2000001), invfact.resize(2000001);
    fact[0] = 1;
    for(int i = 1; i <= 2000000; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invfact.back() = inv(fact.back());
    for(int i = 2000000 - 1; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    int n; cin >> n;
    if(n % 2) solve_odd(n);
    else solve_even(n);
}