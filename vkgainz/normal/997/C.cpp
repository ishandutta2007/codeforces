#include <bits/stdc++.h>
using namespace std;

vector<long long> fact, inver, power;
long long MOD = 998244353;

long long inv(long long b, long long p) {
    if(p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

long long choose(int a, int b) {
    if(b > a) return 0LL;
    return fact[a] * inver[b] % MOD * inver[a - b] % MOD;
}

int main() {
    int n; cin >> n;
    power.resize(n + 1);
    power[0] = 1LL;
    for(int i = 1; i <= n; i++)
        power[i] = power[i - 1] * 3 % MOD;
    fact.resize(n + 1), inver.resize(n + 1);
    fact[0] = 1LL, inver[0] = 1LL;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * 1LL * i % MOD;
    inver[n] = inv(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--)
        inver[i] = inver[i + 1] * (i + 1) % MOD;
    
    long long ans = inv(power[n] - 3, n);
    for(int i = 1; i <= n; i++) {
        long long add = 0LL;
        add += 3 * 1LL * inv(power[n - i] - 1, n);
        add += (power[i] - 3) * 1LL * inv(power[n - i], n);
        add %= MOD;
        add *= choose(n, i);
        add %= MOD;
        if(i % 2) ans -= add;
        else ans += add;
        ans %= MOD;
    }
    ans = inv(3, n * 1LL * n) - ans;
    ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans;
}