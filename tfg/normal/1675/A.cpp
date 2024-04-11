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
        int a, b, c, x, y;
        std::cin >> a >> b >> c >> x >> y;
        x = std::max(0, x-a);
        y = std::max(0, y-b);
        std::cout << (x + y <= c ? "YES\n" : "NO\n");
    }
}