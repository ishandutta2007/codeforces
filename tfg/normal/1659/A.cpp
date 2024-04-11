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
        int n, r, b;
        std::cin >> n >> r >> b;
        std::vector<int> freq(b+1, 0);
        for(int i = 0; i < r; i++) {
            freq[i%(b+1)]++;
        }
        for(int i = 0; i <= b; i++) {
            while(freq[i]--) std::cout << 'R';
            if(i < b) std::cout << 'B';
        }
        std::cout << '\n';
    }
}