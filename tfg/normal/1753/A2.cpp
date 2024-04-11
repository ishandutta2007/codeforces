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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<std::pair<int, int>> ranges;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        for(int i = 0; i < n; i++) {
            if(i+1 < n && std::abs(sum - 2 * a[i+1]) < std::abs(sum)) {
                sum -= 2 * a[i+1];
                ranges.emplace_back(i, i+1);
                i++;
            } else {
                ranges.emplace_back(i, i);
            }
        }
        if(sum == 0) {
            std::cout << ranges.size() << '\n';
            for(auto [l, r] : ranges) {
                std::cout << l+1 << ' ' << r+1 << '\n';
            }
        } else {
            std::cout << "-1\n";
        }
    }
}