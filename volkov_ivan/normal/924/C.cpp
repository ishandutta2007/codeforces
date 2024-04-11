#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d ", &arr[i]);
    }
    int dp[n + 1];
    dp[n] = arr[n] + 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = max(dp[i + 1] - 1, arr[i] + 1);
    }
    long long ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt - arr[i];
        if (dp[i] == cnt + 1) {
            cnt++;
        } else {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}