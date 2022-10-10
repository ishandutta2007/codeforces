#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::set<int> b;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            b.insert(b.count(a[i]) == 0 ? a[i] : -a[i]);
        }
        std::cout << b.size() << '\n';
    }
}