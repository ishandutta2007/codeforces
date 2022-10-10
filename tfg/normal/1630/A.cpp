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
    auto cost = [](int x, int y) { return x & y; };
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        int sum = 0;
        //std::cout << "on case (" << n << ", " << k << ")" << std::endl;
        if(k+1 == n && n == 4) {
            std::cout << "-1\n";
            continue;
        } else if(k == 0) {
            for(int i = 0; i < n/2; i++) {
                std::cout << i << ' ' << n-i-1 << '\n';
                sum += cost(i, n-i-1);
            }
        } else if(k < n-1) {
            std::cout << 0 << ' ' << n - k - 1 << '\n';
            std::cout << k << ' ' << n - 1 << '\n';
            sum += cost(0, n-k-1);
            sum += cost(k, n-1);
            for(int i = 1; i < n/2; i++) if(i != k && i != n - k - 1) {
                std::cout << i << ' ' << n-i-1 << '\n';
                sum += cost(i, n-i-1);
            }
        } else {
            std::cout << 0 << ' ' << n-3 << '\n';
            std::cout << 1 << ' ' << 3 << '\n';
            std::cout << n-2 << ' ' << n - 1 << '\n';
            std::cout << 2 << ' ' << n-4 << '\n';
            sum += cost(0, n-3) + cost(3, 1) + cost(n-2, n-1) + cost(2, n-4);
            for(int i = 4; i < n/2; i++) {
                std::cout << i << ' ' << n-i-1 << '\n';
                sum += cost(i, n-i-1);
            }
        }
        assert(sum == k);
    }
}