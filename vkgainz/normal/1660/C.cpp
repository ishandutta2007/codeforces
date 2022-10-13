#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<int> dp(s.length() + 1);
        vector<int> lst(26, 5 * s.length());
        for (int i = s.length() - 1; i >= 0; i--) {
            if (i == s.length() - 1) dp[i] = 1;
            else {
                dp[i] = 1 + dp[i + 1];
                if (lst[s[i] - 'a'] < s.length()) {
                    dp[i] = min(dp[i], lst[s[i] - 'a'] - i - 1
                            + dp[lst[s[i] - 'a'] + 1]);
                }
            }
            lst[s[i] - 'a'] = i;
        }
        cout << dp[0] << "\n";
    }
}