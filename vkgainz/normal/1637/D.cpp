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
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int totSum = accumulate(a.begin(), a.end(), 0)
               + accumulate(b.begin(), b.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(totSum + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= totSum; j++) {
                if (j >= a[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
                }
                if (j >= b[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - b[i - 1]];
                }
            }
        }
        long long ans = 0LL;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += (a[i] * a[i] + a[j] * a[j]);
                ans += (b[i] * b[i] + b[j] * b[j]);
            }
            ans -= a[i] * a[i];
            ans -= b[i] * b[i];
        }
        long long mn = 1e12;
        for (int i = 0; i <= totSum; i++) {
            if (dp[n][i]) {
                mn = min(mn, (long long) i * i + (totSum - i) * (totSum - i));
            }
        }
        cout << ans + mn << "\n";
    }
}