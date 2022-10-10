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
        int ans = 0;
        while(n--) {
            int x;
            std::cin >> x;
            ans ^= (x+1) % 2;
        }
        std::cout << (ans ? "errorgorn\n" : "maomao90\n");
    }
}