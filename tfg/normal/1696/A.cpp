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
        int n, z;
        std::cin >> n >> z;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            ans = std::max(ans, z | x);
        }
        std::cout << ans << '\n';
    }
}