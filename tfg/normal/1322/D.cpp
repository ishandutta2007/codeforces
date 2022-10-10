#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[n-i-1];
        a[n-i-1]--;
    }
    std::vector<int> cost(n);
    for(int i = 0; i < n; i++) {
        std::cin >> cost[n-i-1];
    }
    std::vector<int> profit(n+m);
    for(int i = 0; i < n+m; i++) {
        std::cin >> profit[i];
    }
    const int INF = 1e9;
    const int sz = n + m;
    std::vector<std::vector<int>> table(sz+1, std::vector<int>(n+2, -INF));
    for(int i = 0; i <= sz; i++) {
        table[i][0] = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int curSize = 0;
        while(table[a[i]][curSize] > -INF) curSize++;
        std::vector<int> dp(curSize+1, 0);
        for(int j = 1; j <= curSize; j++) {
            dp[j] = table[a[i]][j-1] - cost[i];
            int x = j * 2;
            for(int k = 0; (x & (1 << k)) == 0; k++) {
                dp[j] += profit[a[i]+k];
            }
            ans = std::max(ans, dp[j]);
        }
        for(int j = 1; j <= curSize; j++) {
            table[a[i]][j] = std::max(table[a[i]][j], dp[j]);
        }
        for(int j = a[i]; j < sz; j++, curSize /= 2) {
            for(int k = 0; k <= curSize; k++) {
                table[j+1][k/2] = std::max(table[j+1][k/2], table[j][k]);
            }
        }
    }
    std::cout << ans << '\n';
}