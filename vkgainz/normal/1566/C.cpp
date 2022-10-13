#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            num[i] = (1 << (a[i] - '0')) | (1 << (b[i] - '0'));
        }
        vector<int> dp(n + 1);
        int lst0 = -1, lst1 = -1;
        for (int i = 1; i <= n; i++) {
            if (num[i - 1] == 3) dp[i] = dp[i - 1] + 2;
            else if (num[i - 1] == 1) {
                dp[i] = dp[i - 1] + 1;
                if (lst1 != -1) {
                    dp[i] = max(dp[lst1 - 1] + 2, dp[i]);
                }
                lst0 = i;
            }
            else if (num[i - 1] == 2) {
                dp[i] = dp[i - 1];
                if (lst0 != -1) {
                    dp[i] = max(dp[lst0 - 1] + 2, dp[i]);
                }
                lst1 = i;
            }
        }
        cout << dp.back() << "\n";
    }
}