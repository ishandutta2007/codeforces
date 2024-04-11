#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <chrono>
 
using namespace std;
 
int dp[51][51][51][51];
int sum[51][51];

int main() {
    int n; cin >> n;
    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if (grid[i - 1][j - 1] == '#') {
                ++sum[i][j];
            }
        }
    }
    for (int i2 = 1; i2 <= n; i2++) {
        for (int j2 = 1; j2 <= n; j2++) {
            for (int i = i2; i >= 1; i--) {
                for (int j = j2; j >= 1; j--) {
                    int tot = sum[i2][j2] - sum[i - 1][j2]
                        - sum[i2][j - 1] + sum[i - 1][j - 1];
                    dp[i][j][i2][j2] = 1000000;
                    if (tot == 0) {
                        dp[i][j][i2][j2] = 0;
                    } else {
                        if (tot == 1) {
                            dp[i][j][i2][j2] = 1;
                        } else {
                            dp[i][j][i2][j2] = max(i2 - i + 1,
                                    j2 - j + 1);
                        }
                        //min stuff
                        for (int x = i; x < i2; x++) {
                            dp[i][j][i2][j2] = min(dp[i][j][i2][j2],
                                    dp[i][j][x][j2] + dp[x + 1][j][i2][j2]);
                        }
                        for (int y = j; y < j2; y++) {
                            dp[i][j][i2][j2] = min(dp[i][j][i2][j2], 
                                    dp[i][j][i2][y] + dp[i][y + 1][i2][j2]);
                        }
                    }
                }
            }
        }
    }
    cout << dp[1][1][n][n];
}