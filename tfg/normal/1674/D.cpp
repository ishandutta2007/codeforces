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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for(int i = n-1; i > 0; i -= 2) {
            if(a[i] < a[i-1]) {
                std::swap(a[i], a[i-1]);
            }
        }
        auto b = a;
        std::sort(b.begin(), b.end());
        if(a == b) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}