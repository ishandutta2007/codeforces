#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<long long> lcm(51);
    lcm[1] = 1LL;
    for(int i = 2; i <= 50; i++) {
        lcm[i] = (lcm[i - 1] * 1LL * i) / __gcd(lcm[i - 1], (long long) i);
    }
    while(t--) {
        long long n; cin >> n;
        long long ans = 0LL;
        long long MOD = 1e9 + 7;
        for(int i = 2; i <= 50; i++) {
            long long freq = 0LL;
            if(lcm[i - 1] <= n) {
                freq = n / lcm[i - 1] - n / lcm[i];
                ans += freq * 1LL * i;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
        
    }
}