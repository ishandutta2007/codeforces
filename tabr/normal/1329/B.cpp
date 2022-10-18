#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;

    while (tt--) {
        ll d, m;
        cin >> d >> m;
        ll x = 1, c = 1;
        while (x * 2 <= d) {
            x *= 2;
            c++;
        }
        vector<ll> dp(c + 1);
        dp[1] = 1;
        ll sum = 1;
        for (int i = 1; i < c; i++) {
            dp[i + 1] = sum * (1LL << (i - 1)) % m;
            sum += dp[i + 1];
            sum %= m;
        }
        dp[c] = sum * (d - x + 1);
        sum += dp[c];
        sum %= m;
        sum += m - 1;
        cout << sum % m << '\n';
    }
    return 0;
}