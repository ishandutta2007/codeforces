#include <iostream>
#include <vector>

using namespace std;

long long dp[4500005], ans[4500005];

int main() {
    int n;
    long long m; cin >> n >> m;
    dp[n] = 1LL, ans[n] = 1LL;
    //dp[i] stores ans[i] + ans[i + 1]...
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = dp[i + 1];
        for (int j = 2; j <= (n) / i; j++) {
            ans[i] += dp[j * i];
            ans[i] -= dp[min((j) * (i + 1), 4000005)];
            ans[i] %= m;
        }
        dp[i] = ans[i] + dp[i + 1];
        dp[i] %= m;
    }
    if (ans[1] < 0) ans[1] += m;
    cout << ans[1] << "\n";
}