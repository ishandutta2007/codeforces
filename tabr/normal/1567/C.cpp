#include <bits/stdc++.h>
using namespace std;
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
        long long n;
        cin >> n;
        vector<int> a(10);
        for (int i = 0; i < 10; i++) {
            a[i] = (int) (n % 10);
            n /= 10;
        }
        vector<vector<long long>> dp(11, vector<long long>(4));
        dp[0][0] = 1;
        vector<int> c(20);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i + j]++;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 4; j++) {
                int b = a[i];
                if (j & 1) {
                    b--;
                }
                if (b != -1) {
                    dp[i + 1][j / 2] += c[b] * dp[i][j];
                }
                b += 10;
                dp[i + 1][2 + j / 2] += c[b] * dp[i][j];
            }
        }
        cout << dp[10][0] - 2 << '\n';
    }
    return 0;
}