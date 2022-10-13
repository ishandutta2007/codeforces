#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int leq[5001][5001];
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                leq[i][j] = -1;
        for (int j = n - 2; j >= 0; j--) {
            if (s[j] < s[n - 1])
                leq[n - 1][j] = 0;
        }
        for (int j = n - 2; j >= 0; j--) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] < s[j])
                    leq[j][i] = 0;
                else if (s[i] == s[j]) {
                    if (leq[j + 1][i + 1] >= 0)
                        leq[j][i] = 1 + leq[j + 1][i + 1];
                }
            }
        }
        vector<int> dp(n);
        dp[0] = n;
        for (int i = 1; i < n; i++) {
            dp[i] = n - i;
            for (int j = i - 1; j >= 0; j--) {
                if (leq[i][j] >= 0)
                    dp[i] = max(dp[i], n - i - leq[i][j] + dp[j]);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}