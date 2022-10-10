#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;
const int me = 10;

int dp[ms][me+1], to[ms][me+1];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    for(int sum = 0; sum < ms; sum++) {
        for(int i = 0; i <= me; i++) {
            if(sum == 0) {
                dp[sum][i] = 0;
                continue;
            }
            for(int j = 1; j < 10 && sum-j >= 0; j++) if(j != i && dp[sum-j][j] >= 0) {
                dp[sum][i] = std::max(dp[sum][i], dp[sum-j][j] + 1);
                if(dp[sum][i] == dp[sum-j][j] + 1) {
                    to[sum][i] = j;
                }
            }
        }
    }
    int t;
    std::cin >> t;
    while(t--) {
        std::string ans;
        int n;
        std::cin >> n;
        for(int sum = n, blocked = 10; sum > 0; sum -= (int) ans.back() - '0', blocked = (int) ans.back() - '0') {
            assert(dp[sum][blocked] >= 1);
            ans += char(to[sum][blocked] + '0');
        }
        std::cout << ans << '\n';
    }
}