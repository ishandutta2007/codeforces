#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long inv(long long b, long long p = MOD - 2) {
    if(p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(i < n - 1 && s[i] == '1' && s[i + 1] == '1') {
                ++b, ++i;
            }
            else if(s[i] == '0') {
                ++a;
            }
        }
        long long ans = 1LL;
        for(int i = 0; i < a + b; i++) ans *= (i + 1), ans %= MOD;
        for(int i = 0; i < a; i++) ans *= inv(i + 1), ans %= MOD;
        for(int i = 0; i < b; i++) ans *= inv(i + 1), ans %= MOD;
        cout << ans << "\n";
    }
}