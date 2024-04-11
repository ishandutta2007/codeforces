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
    vector<int> dp(1001);
    vector<vector<int>> sto(1001);
    dp[1] = 0;
    sto[1].push_back(1);
    for (int i = 2; i <= 1000; i++) {
        dp[i] = 100000;
        for (int j = 1; j < i; j++) {
            for (int k : sto[j]) {
                if (j + k == i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        sto[i].push_back(i);
        for (int k = 2; k <= i; k++) {
            if (i / k != i / (k -  1)) {
                sto[i].push_back(i / k);
            }
        }
    }
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += dp[b[i]];
        }
        if (tot < k) {
            cout << accumulate(c.begin(), c.end(), 0) << "\n";
            continue;
        }
        vector<vector<int>> num(n + 1, vector<int>(k + 1));
        num[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j)
                    num[i][j] = num[i][j - 1];
                num[i][j] = max(num[i][j], num[i - 1][j]);
                if (j >= dp[b[i - 1]]) {
                    num[i][j] = max(num[i][j], num[i - 1][j - dp[b[i - 1]]] + c[i - 1]);
                }
            }
        }
        cout << num[n][k] << "\n";
    }
}