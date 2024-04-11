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
        int x, y;
        std::cin >> x >> y;
        if(x > y) std::cout << x + y << '\n';
        else if(x == y) std::cout << x << '\n';
        else {
            x = y / x * x;
            std::cout << (x + y) / 2 << '\n';
        }
    }
}