#include <bits/stdc++.h>
using namespace std;
 
#define rsz(x, n) x.clear(), x.resize(n)
#define sz(x) (int) x.size()
 
vector<long long> fact, invfact;
long long MOD = 1e9 + 7;

long long inv(long long b, long long p = MOD - 2) {
    if(p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

long long choose(int a, int b) {
    if(b > a || b < 0) return 0LL;
    return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
}

long long test(int x, int &n, int l, int r, int k) {
    if(l + x > n || r - x < 1) return 0;
    int le = min(n, l + x);
    le = max(le, 1);
    int ri = max(1, r - x);
    ri = min(ri, n);
    if(le > ri + 1) return 0LL;
    int intersect = ri - le + 1;
    int a = le - 1;
    return choose(intersect, k - a);
}

int main() {
    
    int t; cin >> t;
    fact.resize(200001), invfact.resize(200001);
    fact[0] = 1LL, invfact[0] = 1LL;
    for(int i = 1; i <= 200000; i++)
        fact[i] = fact[i - 1] * i % MOD, invfact[i] = inv(fact[i]);
    while(t--) {
        int n, l, r; cin >> n >> l >> r;
        long long ans = 0LL;
        if(n % 2 == 0) {
            int num = min(1 - l, r - n);
            ans += num * 1LL * choose(n, n / 2) % MOD;
            for(int x = num + 1; x <= num + n; x++) {
                ans += test(x, n, l, r, n / 2);
                ans %= MOD;
            }
            cout << ans << "\n";
        }
        else {
            int num = min(1 - l, r - n);
            ans += num * 1LL * choose(n, n / 2) % MOD * 2 % MOD;
            for(int x = num + 1; x <= num + n; x++) {
                ans += test(x, n, l, r, n / 2);
                ans += test(x, n, l, r, n / 2 + 1);
                ans %= MOD;
            }
            cout << ans << "\n";
        }
    }
}