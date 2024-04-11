#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        std::vector<int> pos(n+1, 0);
        std::vector<long long> suffixSum(n+1, 0);
        for(int i = 1; i <= n; i++) {
            std::cin >> pos[i];
        }
        for(int i = n; i > 0; i--) {
            suffixSum[i-1] = suffixSum[i] + pos[i];
        }
        long long ans = 1e18;
        for(int i = 0; i <= n; i++) {
            long long curCost = (suffixSum[i]-(long long)(n-i)*pos[i])*b + (long long) pos[i] * (a + b);
            //std::cout << "ending movement at " << i << " got " << curCost << '\n';
            ans = std::min(ans, curCost);
        }
        std::cout << ans << '\n';
    }
}