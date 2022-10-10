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
        int l = n + 20, r = -1;
        for(int i = 0; i+1 < n; i++) {
            if(a[i] == a[i+1]) {
                l = std::min(l, i);
                r = std::max(r, i);
            }
        }
        if(r == -1 || l == r) {
            std::cout << "0\n";
        } else {
            std::cout << std::max(1, r-l-1) << '\n';
        }
    }
}