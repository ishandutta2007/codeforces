#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int x, d;
        std::cin >> x >> d;
        std::vector<int> divs;
        for(int i = 1; i * i <= x; i++) if(x % i == 0) {
            divs.push_back(i);
            if(i*i != x) {
                divs.push_back(x/i);
            }
        }
        std::sort(divs.begin(), divs.end());
        std::vector<int> dp(divs.size(), 0);
        dp.back() = 1;
        for(auto val : divs) if(val % d == 0 && val / d % d != 0) {
            for(int i = (int) dp.size() - 1, j = (int) dp.size() - 1; i > 0; i--) if(divs[i] % val == 0) {
                int target = divs[i] / val;
                while(divs[j] != target) j--;
                dp[j] = std::min(2, dp[j] + dp[i]);
            }
        }
        std::cout << (dp[0] >= 2 ? "YES\n" : "NO\n");
    }
}